if [ $1 = "on" ]
then
	rm -rf /etc/nginx/sites-enabled/*
	ln -s /etc/nginx/sites-available/localhost.conf /etc/nginx/sites-enabled/
	service nginx restart 
elif [ $1 = "off" ]
then
	rm -rf /etc/nginx/sites-enabled/*
	ln -s /etc/nginx/sites-available/localhost_indexoff.conf /etc/nginx/sites-enabled/
	service nginx restart
else
	echo "Use ./index on or off for activate or disable autoindex"

fi