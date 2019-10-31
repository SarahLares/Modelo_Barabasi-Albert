# Modelo_Barabasi-Albert
A continuación se presenta un codigo en C++ donde se empleó el algoritmo de Barabási-Albert para generar una red aleatorias complejas libre de escala.

En este modelo se basa en emplear una regla o mecanismo denominado conexión preferencial.  Las redes generadas por este algoritmo poseen una distribución de grado de tipo potencial y se denominan: redes libres de escalas. Las redes de este tipo son muy frecuentes en los sistemas elaborados por el ser humano así como en la naturaleza. Ejemplos de sistemas de este tipo son Internet, el world wide web, redes de citas, y algunas redes sociales, redes eléctricas. El modelo toma el nombre de Albert-László Barabási y Réka Albert autores que lo popularizaron en 1999.

## Funcionamiento del Código

Inicialmente se le solicita al usuario que ingrese:

<ul>
  <li>Numero de nodos totales que tendrá la red <strong>m</strong></li>
  <li>Numero de nodos que tendrá la red inicial <strong>m<sub>0</sub>  < m </strong> </li>
<li>Numero maximo de conexiones que puede hacer un nodo nuevo <strong>k</strong></li>
</ul>

En la función <strong> red_inicial</strong> se se empieza con un conjunto de <strong>m<sub>0</sub> < m </strong> nodos  que son conectados aleatoriamente sin repetir ninguna conexión. Debe notarse que  <strong>m<sub>0</sub> 	&#8805; 2 </strong> y el grado de cada nodo en la red inicial debe ser al menos 1, de otra forma la evolución de la red, a medida que se van añadiendo nodos, haría que éstos permanecieran desconectados completamente de la red. 

En la función <strong>Add_node</strong> los nuevos nodos se añaden a la red de uno a uno. Cada nodo es conectado a <strong>m</strong> nodos de la red con una probabilidad que es proporcional al número de enlaces que posee los nodos de la red, esta probabilidad es calculada en la función <strong>Probability</strong>, es decir, los nuevos nodos se enlazan preferiblemente con los nodos más conectados. Formalmente la probabilidad <strong>p<sub>i</sub></strong> de que un nuevo nodo se conecte con <strong>i </strong> es:

 <a href="https://www.codecogs.com/eqnedit.php?latex={\displaystyle&space;p_{i}={\frac&space;{k_{i}}{\displaystyle&space;\sum&space;_{j}k_{j}}}}," target="_blank"><img src="https://latex.codecogs.com/gif.latex?{\displaystyle&space;p_{i}={\frac&space;{k_{i}}{\displaystyle&space;\sum&space;_{j}k_{j}}}}," title="{\displaystyle p_{i}={\frac {k_{i}}{\displaystyle \sum _{j}k_{j}}}}," /></a>

donde <strong>k<sub>i</sub></strong> es el grado del nodo <strong>i</strong>, esto es realizado en la función <strong>Pre_Att</strong>. Los nodos con gran cantidad de conexiones tienden a acumular rápidamente más enlaces, mientras que los que poseen pocos enlaces rara vez son el origen de nuevos enlaces. Los nuevos nodos según este algoritmo se dice que poseen una "preferencia" a ser enlazados con los nodos más solicitados. Este algoritmo se fundamenta en el concepto de "conexión prefencial" de los nuevos nodos que se incorporan a la red.
 
 Por último, esto es realizado las veces necesarias para completar la red en la función <strong>BA_model</strong> y devuelve un archivo donde se guardan la distribución final de la red <strong>BA_network.dat</strong> y otro <strong>BA_model.dat</strong> donde se guarda el grado de conexión de cada nodo para graficarlo y poder ver que sigue la ley de potencia.
