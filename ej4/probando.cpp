#include <iostream>
#include <string>

// Declaraciones adelantadas para la relación friend
class CajaDeAhorro;
class CuentaCorriente;

// Clase abstracta base
class Cuenta {
protected:
    double balance;
    std::string titularCuenta;
    
public:
    // Constructor
    Cuenta(const std::string& titular, double balanceInicial = 0.0) : 
           titularCuenta(titular), balance(balanceInicial) {}
    
    // Destructor virtual
    virtual ~Cuenta() {}
    
    // Método para depositar dinero
    void depositar(double cantidad) {
        if (cantidad > 0) {
            balance += cantidad;
            std::cout << "Se depositaron $" << cantidad << " correctamente." << std::endl;
        } else {
            std::cout << "Error: La cantidad a depositar debe ser positiva." << std::endl;
        }
    }
    
    // Método virtual puro para retirar dinero - debe implementarse en las clases derivadas
    virtual bool retirar(double cantidad) = 0;
    
    // Método virtual puro para mostrar información - debe implementarse en las clases derivadas
    virtual void mostrarInfo() = 0;
    
    // Getters
    double getBalance() const { return balance; }
    std::string getTitular() const { return titularCuenta; }
};

// Clase derivada CajaDeAhorro
class CajaDeAhorro : public Cuenta {
private:
    int contadorConsultas;
    
public:
    // Declarar CuentaCorriente como clase amiga
    friend class CuentaCorriente;
    
    // Constructor
    CajaDeAhorro(const std::string& titular, double balanceInicial = 0.0) : 
                Cuenta(titular, balanceInicial), contadorConsultas(0) {}
    
    // Implementación del método retirar
    bool retirar(double cantidad) override {
        if (cantidad <= 0) {
            std::cout << "Error: La cantidad a retirar debe ser positiva." << std::endl;
            return false;
        }
        
        if (cantidad > balance) {
            std::cout << "Error: Fondos insuficientes en la Caja de Ahorro." << std::endl;
            return false;
        }
        
        balance -= cantidad;
        std::cout << "Se retiraron $" << cantidad << " de la Caja de Ahorro." << std::endl;
        return true;
    }
    
    // Implementación del método mostrarInfo
    void mostrarInfo() override {
        contadorConsultas++;
        std::cout << "=== Información de Caja de Ahorro ===" << std::endl;
        std::cout << "Titular: " << titularCuenta << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
        std::cout << "Tipo de cuenta: Caja de Ahorro" << std::endl;
        
        // Aplicar descuento después de 2 consultas
        if (contadorConsultas > 2) {
            balance -= 20;
            std::cout << "Se aplicó un cargo de $20 por exceso de consultas." << std::endl;
            std::cout << "Nuevo balance: $" << balance << std::endl;
        }
    }
};

// Clase derivada CuentaCorriente
class CuentaCorriente : public Cuenta {
private:
    // Referencias a la caja de ahorro asociada
    CajaDeAhorro* cajaAsociada;
    
public:
    // Constructor
    CuentaCorriente(const std::string& titular, double balanceInicial = 0.0, CajaDeAhorro* caja = nullptr) : 
                   Cuenta(titular, balanceInicial), cajaAsociada(caja) {}
    
    // Implementación del método retirar
    bool retirar(double cantidad) override {
        if (cantidad <= 0) {
            std::cout << "Error: La cantidad a retirar debe ser positiva." << std::endl;
            return false;
        }
        
        if (cantidad <= balance) {
            balance -= cantidad;
            std::cout << "Se retiraron $" << cantidad << " de la Cuenta Corriente." << std::endl;
            return true;
        } 
        else if (cajaAsociada != nullptr) {
            std::cout << "Fondos insuficientes en Cuenta Corriente. Intentando retirar de Caja de Ahorro..." << std::endl;
            
            // Como CuentaCorriente es friend de CajaDeAhorro, podemos acceder directamente a sus miembros privados
            if (cajaAsociada->balance >= cantidad) {
                cajaAsociada->balance -= cantidad;
                std::cout << "Se retiraron $" << cantidad << " de la Caja de Ahorro asociada." << std::endl;
                return true;
            } else {
                std::cout << "Error: La cuenta no posee dinero suficiente." << std::endl;
                return false;
            }
        } 
        else {
            std::cout << "Error: La cuenta no posee dinero suficiente y no hay Caja de Ahorro asociada." << std::endl;
            return false;
        }
    }
    
    // Implementación del método mostrarInfo
    void mostrarInfo() override {
        std::cout << "=== Información de Cuenta Corriente ===" << std::endl;
        std::cout << "Titular: " << titularCuenta << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
        std::cout << "Tipo de cuenta: Cuenta Corriente" << std::endl;
        
        if (cajaAsociada != nullptr) {
            std::cout << "Caja de Ahorro asociada - Balance: $" << cajaAsociada->balance << std::endl;
        } else {
            std::cout << "No hay Caja de Ahorro asociada." << std::endl;
        }
    }
    
    // Método para asociar una caja de ahorro
    void asociarCajaDeAhorro(CajaDeAhorro* caja) {
        cajaAsociada = caja;
    }
    
    // Método para verificar fondos totales
    void verificarFondosTotales() const {
        double totalFondos = balance;
        
        if (cajaAsociada != nullptr) {
            totalFondos += cajaAsociada->balance;  // Acceso directo gracias a friend
            std::cout << "Fondos totales (CC + CA): $" << totalFondos << std::endl;
        } else {
            std::cout << "Solo fondos de CC: $" << totalFondos << std::endl;
        }
    }
};

// Código para probar la implementación
int main() {
    // Crear instancias
    CajaDeAhorro caja("Juan Pérez", 1000);
    CuentaCorriente cuenta("Juan Pérez", 500, &caja);
    
    std::cout << "=== Prueba de CajaDeAhorro ===" << std::endl;
    caja.mostrarInfo();  // Primera consulta
    caja.mostrarInfo();  // Segunda consulta
    caja.mostrarInfo();  // Tercera consulta (debe aplicarse el cargo)
    
    std::cout << "\n=== Prueba de retiro de CajaDeAhorro ===" << std::endl;
    caja.retirar(500);   // Debe permitir el retiro
    caja.retirar(5000);  // Debe rechazar el retiro por fondos insuficientes
    
    std::cout << "\n=== Prueba de CuentaCorriente ===" << std::endl;
    cuenta.mostrarInfo();
    cuenta.retirar(300); // Debe permitir el retiro
    cuenta.mostrarInfo();
    
    std::cout << "\n=== Prueba de retiro excediendo el balance de CuentaCorriente ===" << std::endl;
    cuenta.retirar(500); // Debe intentar retirar de la caja de ahorro
    
    std::cout << "\n=== Verificación de fondos usando acceso friend ===" << std::endl;
    cuenta.verificarFondosTotales();
    
    return 0;
}