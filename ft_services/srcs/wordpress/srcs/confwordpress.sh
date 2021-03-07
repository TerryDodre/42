OLDIFS=${IFS}
IFS=.
set -- $(minikube ip)
if [ "${4}" -lt 127 ]; then
	METALLB_RANGE="${1}.${2}.${3}.127"
else
	METALLB_RANGE="${1}.${2}.${3}.1"
fi
IFS=${OLDIFS}
echo "wp core install --url=https://"${METALLB_RANGE}":5050 --title=site --admin_user=admin --admin_password=admin --admin_email=admin@site.fr --path='usr/share/webapps/wordpress/' --skip-email" > srcs/wordpress/srcs/setup.sh
echo "while [ \$? -ne 0 ] ; do" >> srcs/wordpress/srcs/setup.sh
echo "    wp core install --url=https://"${METALLB_RANGE}":5050 --title=site --admin_user=admin --admin_password=admin --admin_email=admin@site.fr --path='usr/share/webapps/wordpress/' --skip-email" >> srcs/wordpress/srcs/setup.sh
echo "done" >> srcs/wordpress/srcs/setup.sh
echo "wp core install --url=https://"${METALLB_RANGE}":5050 --title=site --admin_user=admin --admin_password=admin --admin_email=admin@site.fr --path='usr/share/webapps/wordpress/' --skip-email" >> srcs/wordpress/srcs/setup.sh
echo "wp user create test test@test.fr --first_name=test --last_name=test --user_pass=test --allow-root --path='usr/share/webapps/wordpress/'" >> srcs/wordpress/srcs/setup.sh
echo "wp user create user user@user.fr --first_name=user --last_name=user --user_pass=user --allow-root --path='usr/share/webapps/wordpress/'" >> srcs/wordpress/srcs/setup.sh
echo "(telegraf conf &) & php-fpm7 && nginx -g \"daemon off;\"" >> srcs/wordpress/srcs/setup.sh
