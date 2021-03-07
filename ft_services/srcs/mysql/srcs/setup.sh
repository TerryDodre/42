# Install MariaDB database
mysql_install_db --user=mysql --datadir=/var/lib/mysql
mkdir /run/openrc
touch /run/openrc/softlevel
openrc

rc-service mariadb start

# Create Wordpress database.
mysql -u root --execute="CREATE DATABASE wordpress;"
# Create new user "user" with password "user" and give permissions for PhpMyAdmin.
mysql -u root --execute="CREATE USER 'user'@'%' IDENTIFIED BY 'user'; GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' WITH GRANT OPTION; USE wordpress; FLUSH PRIVILEGES;"
# Create new user "name" with password "name" and give permissions for Wordpress.
mysql -u root --execute="CREATE USER 'name'@'%' IDENTIFIED BY 'name'; GRANT ALL PRIVILEGES ON *.* TO 'name'@'%' WITH GRANT OPTION; USE wordpress; FLUSH PRIVILEGES;"

rc-service mariadb restart
pkill mysqld
(telegraf conf &) & /usr/bin/mysqld --user=root --datadir=/var/lib/mysql