#!bin/bash
sleep 10

# Update and download core wordpress
wp-cli.phar cli update --yes --allow-root
wp-cli.phar core download --allow-root

# Configure wordpress if it hasn't been configured yet
if [ ! -e /var/www/wordpress/wp-config.php ]; then
	wp-cli.phar config create \
		--allow-root \
		--dbname=$DB_NAME \
		--dbuser=$DB_USER \
		--dbpass=$DB_PASS \
		--dbhost=mariadb:3306 --path='/var/www/wordpress'

# Wait for the database configuration to finish
sleep 2

# Create wordpress root user
wp-cli.phar core install \
	--allow-root \
	--url=$DOMAIN_NAME \
	--title=$WP_TITLE \
	--admin_user=$WP_ADMIN_USER \
	--admin_password=$WP_ADMIN_PASS \
	--admin_email=$WP_ADMIN_MAIL \
	--path='/var/www/wordpress' >> /log.txt 2>&1

# Create wordpress default user
wp-cli.phar user create \
	--allow-root \
	--role=author $WP_USER $WP_MAIL \
	--user_pass=$WP_PASS \
	--path='/var/www/wordpress' >> /log.txt 2>&1
fi

if [ ! -d /run/php ]; then
	mkdir ./run/php
fi

# Start Wordpress
/usr/sbin/php-fpm7.3 -F
