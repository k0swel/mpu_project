# Базовый образ с Ubuntu LTS
FROM ubuntu

# Устанавливаем переменные окружения для автоматизации
ENV DEBIAN_FRONTEND=noninteractive
ENV QT_DIR=/opt/qt

# Устанавливаем зависимости Qt5, сборку и SMTP-библиотеки
RUN apt-get update 
RUN apt-get install -y \
build-essential \
qtbase5-dev \
qt5-qmake \
qttools5-dev-tools \
libqt5network5 \
libqt5core5a \
libssl-dev \
ca-certificates \
&& rm -rf /var/lib/apt/lists/*


WORKDIR /app
COPY . .
# Собираем проект

RUN qmake subdirs.pro
RUN make 
RUN chmod +x /app/server/build/server

# Запускаем сервер
CMD ["/app/server/build/server"]