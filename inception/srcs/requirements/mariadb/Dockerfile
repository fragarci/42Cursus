# Select debian base
FROM debian:buster-slim

# Install mariadb
RUN apt-get update -y && apt-get upgrade -y && apt-get install mariadb-server -y

# Copy configuration files
COPY ./tools/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy the configuration script
COPY ./tools/mariadb.sh /

# Give the configuration script execution permissons
RUN chmod +x "/mariadb.sh"

# Use the script as an entrypoint
ENTRYPOINT ["/mariadb.sh"]

# Expose port 3306 (Default port for MySQL)
EXPOSE 3306
