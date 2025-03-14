class Producto:
    def __init__(self, nombre=" ", precio=0, cantinve=0):
        self._nombre = nombre
        self._precio = precio
        self._cantinve = cantinve

    # Getters    
    @property    
    def nombre(self):
        return self._nombre
    
    @property    
    def precio(self):
        return self._precio
    
    @property    
    def cantidad(self):
        return self._cantinve
    
    # Setters
    @nombre.setter
    def nombre(self, nuevo):
        if nuevo.strip():
            self._nombre = nuevo
        else:
            print("no valido")
        
    @precio.setter
    def precio(self, nuevo_precio):
        if nuevo_precio >= 0:
            self._precio = nuevo_precio
        else:
            print("no valido y/O stock incompleto")
    
    @cantidad.setter
    def cantidad(self, nueva_cant):
        if nueva_cant >= 0:
            self._cantinve = nueva_cant
        else:
            print("invalida")






        
        
        
    
