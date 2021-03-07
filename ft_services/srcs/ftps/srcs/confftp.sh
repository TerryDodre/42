OLDIFS=${IFS}
IFS=.
set -- $(minikube ip)
if [ "${4}" -lt 127 ]; then
	METALLB_RANGE="${1}.${2}.${3}.127"
else
	METALLB_RANGE="${1}.${2}.${3}.1"
fi
IFS=${OLDIFS}
echo "adduser -D \"admin\"" > srcs/ftps/srcs/setup.sh
echo "echo \"admin:admin\" | chpasswd\n" >> srcs/ftps/srcs/setup.sh
echo "(telegraf conf &) &" >> srcs/ftps/srcs/setup.sh
echo "openssl req -new -x509 -days 365 -nodes -out /etc/ssl/private/vsftpd.cert.pem -keyout /etc/ssl/private/vsftpd.key.pem -subj \"/C=FR/ST=France/L=Lyon/O=42Lyon/CN=127.0.0.1\"" >> srcs/ftps/srcs/setup.sh
echo "chown root:root /etc/ssl/private/vsftpd.cert.*" >> srcs/ftps/srcs/setup.sh
echo "chmod 600 /etc/ssl/private/vsftpd.cert.*" >> srcs/ftps/srcs/setup.sh
echo "vsftpd -opasv_min_port=21000 -opasv_max_port=21010 -opasv_address="${METALLB_RANGE}" /etc/vsftpd/vsftpd.conf" >> srcs/ftps/srcs/setup.sh