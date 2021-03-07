FROM alpine:3.12

# Expose port
EXPOSE 8086

# Install and Update utils
RUN apk update --no-cache
RUN apk upgrade --no-cache
RUN apk add influxdb --no-cache

# Install Telegraf
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community

# Copy configuration
COPY srcs/telegraf.conf /etc/telegraf/
COPY ./srcs/influxdb.conf /etc/.

# Access setup
COPY ./srcs/setup.sh /setup.sh
RUN chmod +x /setup.sh

ENTRYPOINT ["/bin/sh", "/setup.sh"]