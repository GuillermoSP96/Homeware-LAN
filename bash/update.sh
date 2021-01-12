#!/bin/bash

# exec 1>logs/upgrader_`date +%s`.log 2>&1

echo "The upgrader has started.\r\n"

#Pull from the repository
sudo git pull -f

#Update Python modules
pip3 install -r ../back/requirements.txt

#Build the UI
# cd web
# npm install
# npm run build

#Start services
sudo systemctl restart homewareMQTT
sudo systemctl restart homewareTasks
sudo systemctl restart homeware

echo "\r\The upgrader has finished.\r\n"
