from exp2mod1 import *
class Pedido:
    def __init__(self):
        self.listapro = []
        self.cant_produc = {}  
        self.estado = "pendiente"
        
    def agregar(self, producto, cantidad):
        if cantidad > 0 and cantidad <= producto.cantidad:
            if producto.nombre in self.cant_produc:
             
                self.cant_produc[producto.nombre] += cantidad
                producto.cantidad=producto.cantidad-cantidad
               
                
            else:
                self.listapro.append(producto)
                self.cant_produc[producto.nombre] = cantidad
                producto.cantidad=producto.cantidad-cantidad
                
            print("Agregado a lista de pedidos")
            
        else:
            print("Cantidad no valida/ stock imcompleto")
            
    def mostrar(self):
        if not self.listapro:
            print("Lista vacía")
        else:
            print("\nPedido actual:")
            for producto in self.listapro:
                cant = self.cant_produc[producto.nombre]
                print(f"{producto.nombre} - cantidad: {cant} -stock: {producto.cantidad}")
