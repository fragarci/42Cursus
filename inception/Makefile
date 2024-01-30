all : up

up :
	docker compose -f ./srcs/docker-compose.yml up

down :
	docker compose -f ./srcs/docker-compose.yml down

stop :
	docker compose -f ./srcs/docker-compose.yml stop

start :
	docker compose -f ./srcs/docker-compose.yml start

status :
	docker ps

fclean:
	docker stop $(shell docker ps -qa); docker rm $(shell docker ps -qa); docker rmi -f $(shell docker images -qa); docker volume rm $(shell docker volume ls -q)
	rm -rf /home/fragarci/data/inception/mariadb/*
	rm -rf /home/fragarci/data/inception/wordpress/*

logs:
	docker compose -f ./srcs/docker-compose.yml logs

# docker exec -it mdb mariadb --user root -pPASSWORD
# docker exec -it mariadb mariadb --user root -pfragarci
