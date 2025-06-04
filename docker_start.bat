docker image build -t server-tmp:1.0.0 .
docker container create -p 8080:8080 -i -t --name tmp-container -e TMP_PORT=8080 server-tmp:1.0.0
docker container start -ai tmp-container