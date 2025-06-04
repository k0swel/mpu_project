# Первый этап - собираем ОС, которая соберёт наш сервер
FROM ubuntu:latest AS step_one
# Устанавливаем зависимости Qt5
RUN apt update && apt install -y qt5-qmake qtbase5-dev build-essential && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
# Собираем проект
RUN qmake ./subdirs.pro && make && chmod +x ./server/build/server

# Второй этап - собираем чистую ОС, на которой запустим наш итоговый образ сервера
FROM ubuntu:latest
WORKDIR /app
COPY --from=step_one /app .
RUN apt update && apt install -y libqt5sql5 libqt5network5 openssl ca-certificates libqt5test5
ENTRYPOINT ./unittests/build/unittests && ./server/build/server