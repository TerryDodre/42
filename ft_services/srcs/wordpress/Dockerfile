FROM alpine:3.12

# Expose port
EXPOSE 5050

# Install and Update utils
RUN apk update --no-cache
RUN apk upgrade --no-cache
RUN apk add nginx --no-cache
RUN apk add --no-cache php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session php-phar
RUN apk add openssl --no-cache
RUN apk add openssh --no-cache
RUN apk add wget
RUN apk add openrc
RUN apk add curl

# Install user
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# Install Wordpress
RUN mkdir -p /usr/share/webapps/ && \
	cd /usr/share/webapps/ && \
	wget http://wordpress.org/latest.tar.gz && \
	tar -xzvf latest.tar.gz && \
	rm latest.tar.gz && \
	rm -f /usr/share/webapps/wordpress/wp-config.php && \
    cd ~

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
COPY ./srcs/wp-config.php /usr/share/webapps/wordpress/
COPY ./srcs/telegraf.conf /etc/telegraf/

# Access setup
COPY ./srcs/setup.sh /
RUN chmod +x /setup.sh

ENTRYPOINT ["/bin/sh", "/setup.sh"]