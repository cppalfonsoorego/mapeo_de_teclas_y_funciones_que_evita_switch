# mapeo_de_teclas_y_funciones_que_evita_switch
El repo "mapeo_de_teclas_y_funciones_que_evita_switch" se basa en la idea del vídeo de YT llamado "C++: Punteros a función y delegados [V1][2016_17][Sesión 12]" de @ProfesorRetroman. URL: https://youtu.be/4CQkkPLM_s8?si=JyKMf8lvslCWpAw_
. En dicho vídeo se propone tener en fichero las asociaciones de tecla-func, en vez de estar hardcoded en el fuente. 
. Crear una nueva asociación entre un Código nuevo (tecla) y una Función (acción) ya existente, no requiere editar fuentes ni recompilar. 
. Editar una asociación existente no requiere editar fuentes ni recompilar. Basta cambiarla en el fich de Config. 
. Crear una asociación que incluya una nueva acción (función a ser llamada), sí requiere, obviamente, retocar fuentes, y además añadir al map dicha asoc. 
. El fich de Config contiene las asociaciones cód-func. 
. El fich de llamadas contiene una simulación de pulsación secuencial de teclas, para probar el correcto funcionamiento. 
