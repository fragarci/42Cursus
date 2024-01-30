#!/bin/bash

# Start MySQL in safe mode (& is to start the process on the background)
mysqld_safe &

# Wait for it to start
sleep 10

# Create root user
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ADMIN_PASS}';"

# Create database if it doesn't exist
mysql -uroot -p"${DB_ADMIN_PASS}" -e "CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;"
# Create the default user if it doesn't exist
mysql -uroot -p"${DB_ADMIN_PASS}" -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASS}';"
# Give the new user the required privileges on the databse
mysql -uroot -p"${DB_ADMIN_PASS}" -e "GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASS}';"
mysql -uroot -p"${DB_ADMIN_PASS}" -e "DROP USER IF EXISTS ''@'localhost';"
mysql -uroot -p"${DB_ADMIN_PASS}" -e "FLUSH PRIVILEGES;"
# Shutdown the database to apply all changes
mysqladmin -u root -p$DB_ADMIN_PASS shutdown

# Start MySQL in safe mode again (this time in the foreground)
exec mysqld_safe
