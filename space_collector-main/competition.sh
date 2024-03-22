PORT=$(python -c "import random; print(random.randint(50000, 60000))")
echo "La compétition se passe sur 127.0.0.1:$PORT"

python  -m space_collector.killall.py
find . -name "*.log" -exec rm \{} \;

python -m space_collector.game.server -p $PORT &
python -m space_collector.viewer -p $PORT --small-window &
python -m space_collector.viewer -p $PORT &
sleep 2
# python -m space_collector.serial2tcp -p $PORT &
# python /home/vincent/Documents/programmation/space_collector_player/sample_player_client.py -p $PORT &
# python /home/vincent/Documents/programmation/space_collector_player/sample_player_client.py -p $PORT &
# python /home/vincent/Documents/programmation/space_collector_player/sample_player_client.py -p $PORT &
# python /home/vincent/Documents/programmation/space_collector_player/sample_player_client.py -p $PORT &

sleep 330
python -m space_collector.killall
