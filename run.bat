python hpp2plantuml.py  -i "headers/*.hpp" -o output.puml
java -jar plantuml.jar -verbose output.puml
start chrome output.png