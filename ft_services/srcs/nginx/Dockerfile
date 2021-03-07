FROM alpine:3.12

# Expose port
EXPOSE 80 443 22

# Install and Update utils
RUN apk update --no-cache
RUN apk upgrade --no-cache
RUN apk add nginx --no-cache
RUN apk add openssl --no-cache
RUN apk add openssh --no-cache
RUN apk add openrc --no-cache

# Install Telegraf
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community

#Key Generate
RUN adduser -D -g 'www' www
RUN echo "www:www" | chpasswd
RUN mkdir -p /run/nginx /www /etc/nginx/ssl
RUN chown -R www:www /var/lib/nginx && chown -R www:www /www
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/default.key -out /etc/nginx/ssl/default.crt \
    -subj "/C=FR/ST=France/L=Lyon/O=42Lyon/CN=localhost"

# Copy configuration
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/nginx.conf /etc/nginx/nginx.conf
COPY ./srcs/index.html /

# Access setup
COPY ./srcs/setup.sh /
RUN chmod +x /setup.sh
RUN nginx

ENTRYPOINT ["/bin/sh", "/setup.sh"]