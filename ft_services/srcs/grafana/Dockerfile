FROM alpine:3.12

# Expose port
EXPOSE 3000

# Install and Update utils
RUN apk update --no-cache
RUN apk upgrade --no-cache

# Install Telegraf
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community

# Install Grafana
RUN apk add libc6-compat gcompat
RUN wget https://dl.grafana.com/oss/release/grafana-7.3.6.linux-amd64.tar.gz
RUN tar -zxvf grafana-7.3.6.linux-amd64.tar.gz
RUN rm grafana-7.3.6.linux-amd64.tar.gz

# Copy configuration
COPY srcs/dashboards /grafana-7.3.6/dashboards/.
COPY srcs/dashboard_conf.yaml /grafana-7.3.6/conf/provisioning/dashboards/.
COPY srcs/influxdb.yaml /grafana-7.3.6/conf/provisioning/datasources/.
COPY srcs/telegraf.conf /etc/telegraf/
COPY srcs/grafana.ini /etc/

# Access setup
COPY ./srcs/setup.sh /
RUN chmod +x /setup.sh

ENTRYPOINT ["/bin/sh", "/setup.sh"]