#!/bin/bash

# exec 1>logs/upgrader_`date +%s`.log 2>&1

echo "The upgrader has started.\r\n"

#Pull from the repository
git pull

#Update Python modules
pip3 install -r requirements.txt

#Build the UI
# cd web
# npm install
# npm run build

#Start services
systemctl restart homewareMQTT
systemctl restart homewareTasks
systemctl restart homeware

echo "\r\The upgrader has finished.\r\n"
