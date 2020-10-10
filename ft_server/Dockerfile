FROM        debian:buster
LABEL       maintainer="<tdodre@student.42lyon.fr>"
WORKDIR     /ft_server
COPY        srcs /ft_server
RUN         apt-get update && apt-get upgrade -y
EXPOSE      80 443
ENTRYPOINT  ["sh", "server.sh"]