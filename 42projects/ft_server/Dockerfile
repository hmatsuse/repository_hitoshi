# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:56:34 by matsusehito       #+#    #+#              #
#    Updated: 2020/12/12 01:25:09 by hmatsuse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

# install nginx mysql php
RUN apt-get update -y \
    && apt-get upgrade -y \
    && apt-get install -y apt-utils nginx mariadb-server mariadb-client \
    && apt-get install -y php-cgi php-common php-fpm php-pear php-mbstring \
    && apt-get install -y php-zip php-net-socket php-gd php-xml-util \
    && apt-get install -y php-gettext php-mysql php-bcmath supervisor unzip wget

# wordpress phpmyadmin
RUN wget https://wordpress.org/latest.tar.gz \
    && wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
    && tar -xvzf latest.tar.gz \
    && tar -xvzf phpMyAdmin-5.0.2-all-languages.tar.gz \
    && mv wordpress/ /var/www/html/ \
    && mv phpMyAdmin-5.0.2-all-languages phpmyadmin \
	&& mv phpmyadmin/ /var/www/html/ \
    && rm latest.tar.gz \
    && rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN chown -R www-data:www-data /var/www/html/wordpress
COPY ./srcs/wp-config.php /var/www/html/wordpress/wp-config.php

# mysql
RUN service mysql start \
    && mysql -e "create user 'test'@'localhost' identified by 'password';" \
    && mysql -e "create database wordpress;" \
    && mysql -e "grant all on wordpress.* to 'test'@'localhost';" \
    && mysql -e "flush privileges;" \
    && mysql -e "exit"

# openssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt -subj "/C=JP/ST=Tokyo/L=Roppongi/O=42/OU=IT/CN=localhost"

# supervisor
COPY ./srcs/supervisord.conf /etc/supervisor/conf.d/supervisord.conf
RUN  chmod +x /etc/supervisor/conf.d/supervisord.conf

# entrykit
RUN wget -O entrykit.tgz https://github.com/progrium/entrykit/releases/download/v0.4.0/entrykit_0.4.0_Linux_x86_64.tgz \
	&& tar -xvzf entrykit.tgz \
    && rm entrykit.tgz \
	&& mv entrykit /bin/entrykit \
	&& entrykit --symlink

COPY ./srcs/default.tmpl /etc/nginx/sites-available/default.tmpl

ENTRYPOINT ["render", "/etc/nginx/sites-available/default", "--", "/usr/bin/supervisord"]
