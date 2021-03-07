FROM alpine:3.12

# Expose port
EXPOSE 5000

# Install and Update utils
RUN apk update --no-cache
RUN apk upgrade --no-cache
RUN apk add nginx --no-cache
RUN apk add openssl --no-cache
RUN apk add openssh --no-cache
RUN apk add openrc --no-cache
RUN apk add --no-cache php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

# Install PhpMyAdmin
RUN mkdir -p /www
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages/* /www/.
RUN rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz phpMyAdmin-5.0.2-all-languages

#Key Generate
RUN adduser -D -g 'www' www
RUN echo "www:www" | chpasswd
RUN mkdir -p /run/nginx /www /etc/nginx/ssl
RUN chown -R www:www /var/lib/nginx && chown -R www:www /www
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/default.key -out /etc/nginx/ssl/default.crt \
    -subj "/C=FR/ST=France/L=Lyon/O=42Lyon/CN=localhost"

# Install Telegraf
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community

# Copy configuration
COPY ./srcs/nginx.conf /etc/nginx/nginx.conf
COPY ./srcs/config.inc.php /www/.
COPY ./srcs/telegraf.conf /etc/telegraf/

# Access setup
COPY ./srcs/setup.sh .
RUN chmod +x /setup.sh
RUN chmod a-w /www/config.inc.php

ENTRYPOINT ["/bin/sh", "/setup.sh"]