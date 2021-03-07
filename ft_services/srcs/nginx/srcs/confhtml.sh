OLDIFS=${IFS}
IFS=.
set -- $(minikube ip)
if [ "${4}" -lt 127 ]; then
	METALLB_RANGE="${1}.${2}.${3}.127"
else
	METALLB_RANGE="${1}.${2}.${3}.1"
fi
IFS=${OLDIFS}
echo "<!DOCTYPE html>\n<html>\n<head>\n<title>ft_services</title>\n<style>\nhtml {\nfont-size: 100%;\nheight: 100%;\n}\nbody {\nbackground: linear-gradient(#272640, #212F45);\nbox-sizing: border-box;\nfont-family: 'Source Sans Pro', sans-serif;\nheight: 100%;\nline-height: 1.5;\nmargin: 0;\npadding: 90px;\ntext-align: center;\n}\nh1 {\ncolor: #ffffff;\nfont-size: 4rem;\nfont-weight: bold;\nline-height: 1;\nmargin: 0 0 1rem 0;\n}\np {\ncolor: #ffffff;\nmargin: 0 0 1rem 0;\n}\np1 {\ncolor: #ffffff;\nmargin: 0 0 1rem 0;\nfont-size: 0.8rem;\n}\na {\ncolor: #4C9394;\nfont-size: 1.2rem;\nmargin: 0 0 1rem 0;\ntext-decoration: none;\n}\na:hover, a:active {\ncolor: #2E8182;\n}\n</style>\n</head>\n<body>\n<h1>FT_SERVICES</h1>\n<p>By Tdodre</p>\n<br/>\n<p>Welcome to nginx, if you see this page, the nginx web server is successfully installed and working.</p><br/>" > srcs/nginx/srcs/index.html
echo "<a href=\"http://"${METALLB_RANGE}":5050\" target=\"_blank\">Wordpress</a>\n<br/><br/>" >> srcs/nginx/srcs/index.html
echo "<a href=\"http://"${METALLB_RANGE}":5050/wp-admin\" target=\"_blank\">Wordpress connection</a>\n<br/>\n<p1><em>admin: admin</em></p1><br/>\n<p1><em>password: admin</em></p1><br/>\n<p1><em>user: user</em></p1><br/>\n<p1><em>password: user</em></p1><br/>\n<p1><em>user: test</em></p1><br/>\n<p1><em>password: test</em></p1><br/>" >> srcs/nginx/srcs/index.html
echo "<a href=\"http://"${METALLB_RANGE}":5000\" target=\"_blank\">PhpMyadmin</a>\n<br/>\n<p1><em>user: user</em></p1><br/>\n<p1><em>password: user</em></p1><br/>" >> srcs/nginx/srcs/index.html
echo "<a href=\"http://"${METALLB_RANGE}":3000\" target=\"_blank\">Grafana</a>\n<br/>\n<p1><em>user: user</em></p1><br/>\n<p1><em>password: user</em></p1><br/>" >> srcs/nginx/srcs/index.html
echo "<a>Filezilla</a>\n<br/>\n<p1><em>hote: "${METALLB_RANGE}"</em></p1><br/>\n<p1><em>user: admin</em></p1><br/>\n<p1><em>password: admin</em></p1><br/>\n<p1><em>port: 21</em></p1><br/>" >> srcs/nginx/srcs/index.html
echo "</body>\n</html>" >> srcs/nginx/srcs/index.html

echo "http {" > srcs/nginx/srcs/nginx.conf
echo "\tserver {" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tlisten 443 ssl default_server;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tlisten [::]:443 ssl default_server;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tssl_certificate /etc/nginx/ssl/default.crt;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tssl_certificate_key /etc/nginx/ssl/default.key;" >> srcs/nginx/srcs/nginx.conf
echo "\n\t\t\troot /www/;" >> srcs/nginx/srcs/nginx.conf
echo "\n\t\t\tlocation / {" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\ttry_files \$uri \$uri/ =404;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t}" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tlocation /wordpress {" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\treturn 307  http://\$host:5050/;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t}" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tlocation /phpmyadmin {" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\tproxy_pass          http://"${METALLB_RANGE}":5000/;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\tproxy_set_header    Host \$host;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\tproxy_set_header    X-Real-IP \$remote_addr;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\tproxy_set_header    X-Forwarded-For \$proxy_add_x_forwarded_for;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\tproxy_set_header    X-Forwarded-Proto \$scheme;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t\tproxy_redirect      /index.php  /phpmyadmin/index.php;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\t}" >> srcs/nginx/srcs/nginx.conf
echo "\t}" >> srcs/nginx/srcs/nginx.conf
echo "\n\tserver {" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tlisten 80 default_server;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\tlisten [::]:80 default_server;" >> srcs/nginx/srcs/nginx.conf
echo "\t\t\treturn 301 https://\$host\$request_uri;" >> srcs/nginx/srcs/nginx.conf
echo "\t}" >> srcs/nginx/srcs/nginx.conf
echo "}" >> srcs/nginx/srcs/nginx.conf
echo "\nevents {" >> srcs/nginx/srcs/nginx.conf
echo "}" >> srcs/nginx/srcs/nginx.conf