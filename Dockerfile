# Базовый образ с Ubuntu LTS
FROM ubuntu:latest
# Устанавливаем зависимости Qt5
RUN apt update && apt install -y qt5-qmake qtbase5-dev build-essential && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
# Собираем проект
RUN qmake ./subdirs.pro && make && chmod +x ./server/build/server

# Запускаем сервер
CMD ["./server/build/server"]