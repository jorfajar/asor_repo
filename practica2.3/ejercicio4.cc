Mostrar todos los procesos del usuario actual en formato extendido.
  
ps -u $USER -f

Mostrar los procesos del sistema, incluyendo el identificador del proceso, el identificador del grupo 
de procesos, el identificador de sesión, el estado y el comando con todos sus argumentos.
  
ps -eo, pid, gid, sid, s, command
