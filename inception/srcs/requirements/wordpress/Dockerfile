# Select linux base distro
FROM debian:buster-slim

# Install necessary dependencies for wordpress to work
RUN apt update -y
RUN apt upgrade -y
RUN	apt install -y php7.3 php7.3-fpm php7.3-mysql php7.3-phar mariadb-client wget

# Download and unzip wordpress
RUN	wget https://wordpress.org/wordpress-6.0.tar.gz -P /var/www
RUN	cd /var/www && tar -xzf wordpress-6.0.tar.gz  && rm wordpress-6.0.tar.gz

# Copy the configuration file
COPY ./tools/php.conf /etc/php/7.3/fpm/pool.d/www.conf

# Make root owner of the wordpress directory
RUN	chown -R root:root /var/www/wordpress

# Download configuration files
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

# Add execution permissons to the downloaded file and move it to the desired location
RUN	chmod +x wp-cli.phar
RUN	mv wp-cli.phar /usr/local/bin/wp-cli.phar

# Copy the configuration script and give it execution premisson
COPY tools/wordpress.sh wordpress.sh
RUN chmod +x wordpress.sh

# Start Wordpress with the configuration script
ENTRYPOINT ["bash", "wordpress.sh"]
