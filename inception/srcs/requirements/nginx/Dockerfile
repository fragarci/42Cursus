# Base lixux distro
FROM debian:buster-slim

# Install nginx and openssl
RUN apt update -y && apt upgrade -y && apt install nginx -y && apt install openssl -y

# Create directory for SSL Certificates
RUN	mkdir -p /etc/nginx/ssl

# Generate SSL Certificates
RUN	openssl req -newkey rsa:4096 -days 42 -nodes -x509  \
	 -subj "/C=ES/ST=AN/L=Malaga/O=42/OU=42/CN=fragarci.42.fr/UID=fragarci" \
	 -out /etc/nginx/ssl/inception.crt \
	 -keyout /etc/nginx/ssl/inception.key

# Copy the nginx configuration file
COPY ./tools/nginx.conf /etc/nginx/nginx.conf

# Start nginx without the daemon
ENTRYPOINT ["nginx", "-g", "daemon off;"]
