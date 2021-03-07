FROM alpine:3.12

# Expose port
EXPOSE 3306

# Install and Update utils
RUN apk update --no-cache
RUN apk upgrade --no-cache
RUN apk add mysql --no-cache
RUN apk add mysql-client --no-cache
RUN apk add --no-cache openrc
RUN mkdir -p /run/mysqld

# Install Telegraf
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community

# Copy configuration
COPY ./srcs/my.cnf ./etc/my.cnf.d/
COPY ./srcs/setup.sh /
COPY ./srcs/telegraf.conf /etc/telegraf/

RUN chmod +x /etc/my.cnf.d/my.cnf

# Access setup
COPY ./srcs/setup.sh /
RUN chmod +x /setup.sh

ENTRYPOINT ["/bin/sh", "/setup.sh"]