from exp2mod1 import *
from exp2mod2 import *
# Prueba del código
producto1 = Producto("Pan", 10, 200)
producto2 = Producto("Fideos", 5, 10)
producto3 = Producto("Mouse", 4, 11)

pedido1 = Pedido()
pedido1.agregar(producto1, 2)
pedido1.agregar(producto2, 1)
pedido1.agregar(producto3, 4)

pedido1.mostrar()



print ("---------------")
pedido2= Pedido()
pedido2.agregar(producto1, 2)
pedido2.agregar(producto2, 1)
pedido2.agregar(producto3, 7)
pedido2.mostrar()
