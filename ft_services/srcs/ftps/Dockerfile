FROM alpine:3.12

# Expose port
EXPOSE 21

# Install and Update utils
RUN apk -U upgrade --no-cache
RUN apk add vsftpd \
    && apk add openssl \
    && apk add openrc

# Install Telegraf
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community

# Copy configuration
COPY ./srcs/telegraf.conf /etc/telegraf/
COPY srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
RUN rc-update add vsftpd default

# Access setup
COPY ./srcs/setup.sh /
RUN chmod +x /setup.sh

ENTRYPOINT ["/bin/sh", "/setup.sh"]