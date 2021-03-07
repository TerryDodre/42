#!/bin/sh
# start FT_SERVICE

function help {
	# Get script info 
	echo "${GREEN}./setup.sh [CMD]${END}"
	echo "	setup		Create the cluster"
	echo "	start		Config the cluster"
	echo "	clear		Clear the cluster"
	echo "	delete		Delete the cluster"
	echo "	status		Execute get CMD for info"
	echo "	kill (name)	Kill a deploy"
	echo "${YELLOW}Without argument, ft_service start normally.${END}"
}

function setup {
	# Start Minikube
	echo "${YELLOW}Minikube start${END}"
	# minikube start
	if [ "$OS" == "Darwin" ]; then
		minikube start --driver=hyperkit 
		minikube addons enable metallb > /dev/null 2>&1
		minikube addons enable dashboard > /dev/null 2>&1
		# minikube addons enable metrics-server > /dev/null 2>&1
	else
		minikube start --vm-driver=docker
		minikube addons enable dashboard > /dev/null 2>&1
		minikube addons enable metrics-server > /dev/null 2>&1
	fi
	echo "${GREEN}Minikube is ready${END}"
}

function metallbip {
	# Minikube linked at docker
	eval $(minikube docker-env)
	# MetalLb IP configuration
	OLDIFS=${IFS}
	IFS=.
	set -- $(minikube ip)
	if [ "${4}" -lt 127 ]; then
		METALLB_RANGE="${1}.${2}.${3}.127-${1}.${2}.${3}.127"
	else
		METALLB_RANGE="${1}.${2}.${3}.1-${1}.${2}.${3}.1"
	fi
	IFS=${OLDIFS}
	echo "apiVersion: v1\nkind: ConfigMap\nmetadata:" > srcs/yaml/metallb.yaml
	echo "  namespace: metallb-system\n  name: config\ndata:" >> srcs/yaml/metallb.yaml
	echo "  config: |\n    address-pools:\n    - name: default\n      protocol: layer2\n      addresses:" >> srcs/yaml/metallb.yaml
	echo "      -" ${METALLB_RANGE} >> srcs/yaml/metallb.yaml
	# Other script is config with IP
	chmod +x srcs/nginx/srcs/confhtml.sh
	./srcs/nginx/srcs/confhtml.sh
	chmod +x srcs/ftps/srcs/confftp.sh
	./srcs/ftps/srcs/confftp.sh
	chmod +x srcs/wordpress/srcs/confwordpress.sh
	./srcs/wordpress/srcs/confwordpress.sh
}

function buildimage {
	# Image configuration
	echo "${BLUE}Docker build NGINX ...${END}"
	docker build -t nginx_img srcs/nginx/ > /dev/null 2>&1
	echo "${GREEN}NGINX completed !${END}"
	echo "${BLUE}Docker build WORDPRESS ...${END}"
	docker build -t wordpress_img srcs/wordpress > /dev/null 2>&1
	echo "${GREEN}WORDPRESS completed !${END}"
	echo "${BLUE}Docker build PHPMYADMIN ...${END}"
	docker build -t phpmyadmin_img srcs/phpmyadmin > /dev/null 2>&1
	echo "${GREEN}PHPMYADMIN completed !${END}"
	echo "${BLUE}Docker build MYSQL ...${END}"
	docker build -t mysql_img srcs/mysql > /dev/null 2>&1
	echo "${GREEN}MYSQL completed !${END}"
	echo "${BLUE}Docker build INFLUXDB ...${END}"
	docker build -t influxdb_img srcs/influxdb > /dev/null 2>&1
	echo "${GREEN}INFLUXDB completed !${END}"
	echo "${BLUE}Docker build GRAFANA ...${END}"
	docker build -t grafana_img srcs/grafana > /dev/null 2>&1
	echo "${GREEN}GRAFANA completed !${END}"
	echo "${BLUE}Docker build FTPS ...${END}"
	docker build -t ftps_img srcs/ftps > /dev/null 2>&1
	echo "${GREEN}FTPS completed !${END}"
}

function buildcontainer {
	# Container configuration
	echo "${YELLOW}Deployement init${END}"
	# if [ "$OS" != "Darwin" ]; then
		kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
		kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
	# fi
	kubectl create secret generic -n metallb-system memberlist  --from-literal=secretkey="$(openssl rand -base64 128)"
	kubectl apply -f srcs/yaml/metallb.yaml
	kubectl apply -f srcs/yaml/nginx.yaml
	kubectl apply -f srcs/yaml/wordpress.yaml
	kubectl apply -f srcs/yaml/phpmyadmin.yaml
	kubectl apply -f srcs/yaml/mysql.yaml
	kubectl apply -f srcs/yaml/influxdb.yaml
	kubectl apply -f srcs/yaml/grafana.yaml
	kubectl apply -f srcs/yaml/ftps.yaml
	echo "${GREEN}Deployement completed${END}"
}

function clear {
	# Clear the cluster
	echo "${YELLOW}Clear init${END}"
	kubectl delete --all deployments
	kubectl delete --all pods
	kubectl delete --all services
	echo "${RED}Minikube is clean${END}"
}

function status {
	# Get cluster info
	echo "${BLUE}NODES//////////////////////////////////////////////////////////////////////////${END}"
	kubectl get nodes
	echo "\n${BLUE}DEPLOYMENTS////////////////////////////////////////////////////////////////////${END}"
	kubectl get deployments
	echo "\n${BLUE}SERVICES///////////////////////////////////////////////////////////////////////${END}"
	kubectl get services
	echo "\n${BLUE}PODS///////////////////////////////////////////////////////////////////////////${END}"
	kubectl get pods
}

function kill {
	if [ -z "$infokill" ]; then
		echo "${GREEN}./setup.sh kill [name]${END}"
		echo "	nginx		Kill Nginx"
		echo "	wordpress	Kill Wordpress"
		echo "	phpmyadmin	Kill PhpMyAdmin"
		echo "	influxdb	Kill InfluxDB"
		echo "	mysql		Kill MySql"
		echo "	grafana		Kill Grafana"
		echo "	ftps		Kill Ftps"
		echo "${YELLOW}Without argument, info CMD for kill.${END}"
	else
		echo "${YELLOW}Kill ${infokill}${END}"
		if [ "$infokill" == "nginx" ]; then
			kubectl exec deploy/nginx -- pkill nginx
		elif [ "$infokill" == "wordpress" ]; then
			kubectl exec deploy/wordpress -- pkill nginx
		elif [ "$infokill" == "phpmyadmin" ]; then
			kubectl exec deploy/phpmyadmin -- pkill nginx
		elif [ "$infokill" == "influxdb" ]; then
			kubectl exec deploy/influxdb -- pkill influxd
		elif [ "$infokill" == "ftps" ]; then
			kubectl exec deploy/ftps -- pkill vsftpd
		elif [ "$infokill" == "mysql" ]; then
			kubectl exec deploy/mysql -- pkill mysqld
		elif [ "$infokill" == "grafana" ]; then
			kubectl exec deploy/grafana -- pkill grafana
		fi
		echo "${GREEN}WAIT RESTART ...${END}"
		sleep 10
		echo "\n${BLUE}PODS///////////////////////////////////////////////////////////////////////////${END}"
		kubectl get pods
	fi
}

function color {
	# Color configuration
	if [ "$OS" == "Darwin" ]; then
		RED='\033[1;31m'
		GREEN='\033[1;32m'
		YELLOW='\033[1;33m'
		BLUE='\033[1;34m'
		END='\033[0m'
	else
		RED='\e[0;31m'
		GREEN='\e[0;32m'
		YELLOW='\e[0;33m'
		BLUE='\e[0;34m'
		WHITE='\e[0;0mm'
	fi
}

OS=`uname -s`
color;
if [ -z $1 ]; then
	setup;
	metallbip;
	buildimage;
	buildcontainer;
	sleep 5
	status;
elif [ $1 == "setup" ]; then
	setup;
elif [ $1 == "start" ]; then
	metallbip;
	buildimage;
	buildcontainer;
elif [ $1 == "clear" ]; then
	clear;
elif [ $1 == "delete" ]; then
	clear;
	minikube delete
elif [ $1 == "status" ]; then
	status;
elif [ $1 == "kill" ]; then
	infokill=$2
	kill;
elif [ $1 == "help" ]; then
	help;
fi