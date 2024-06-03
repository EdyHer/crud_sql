#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <iostream>

// Clientes
void createCliente(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Clientes (idcliente, nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2, "Juan");
    pstmt->setString(3, "Pérez");
    pstmt->setString(4, "123456789");
    pstmt->setBoolean(5, 1);
    pstmt->setString(6, "555-1234");
    pstmt->setString(7, "juan.perez@example.com");
    pstmt->setDateTime(8, "2024-06-01 10:00:00");
    pstmt->execute();
    delete pstmt;
}

void readClientes(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Clientes");
    while (res->next()) {
        std::cout << "ID Cliente: " << res->getInt("idcliente") << " ";
        std::cout << "Nombres: " << res->getString("nombres") << " ";
        std::cout << "Apellidos: " << res->getString("apellidos") << " ";
        std::cout << "NIT: " << res->getString("NIT") << " ";
        std::cout << "Género: " << res->getBoolean("genero") << " ";
        std::cout << "Teléfono: " << res->getString("telefono") << " ";
        std::cout << "Correo Electrónico: " << res->getString("correo_electronico") << " ";
        std::cout << "Fecha Ingreso: " << res->getString("fechaingreso") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateCliente(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Clientes SET nombres = ?, telefono = ? WHERE idcliente = ?");
    pstmt->setString(1, "Juan Carlos");
    pstmt->setString(2, "555-5678");
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteCliente(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Clientes WHERE idcliente = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Ventas
void createVenta(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Ventas (idVenta, nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) VALUES (?, ?, ?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setInt(2, 1001);
    pstmt->setString(3, "A");
    pstmt->setDateTime(4, "2024-06-01");
    pstmt->setInt(5, 1);
    pstmt->setInt(6, 1);
    pstmt->setDateTime(7, "2024-06-01 10:00:00");
    pstmt->execute();
    delete pstmt;
}

void readVentas(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Ventas");
    while (res->next()) {
        std::cout << "ID Venta: " << res->getInt("idVenta") << " ";
        std::cout << "No. Factura: " << res->getInt("nofactura") << " ";
        std::cout << "Serie: " << res->getString("serie") << " ";
        std::cout << "Fecha Factura: " << res->getString("fechafactura") << " ";
        std::cout << "ID Cliente: " << res->getInt("idcliente") << " ";
        std::cout << "ID Empleado: " << res->getInt("idempleado") << " ";
        std::cout << "Fecha Ingreso: " << res->getString("fechaingreso") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateVenta(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Ventas SET nofactura = ?, fechafactura = ? WHERE idVenta = ?");
    pstmt->setInt(1, 1002);
    pstmt->setDateTime(2, "2024-06-02");
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteVenta(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Ventas WHERE idVenta = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Empleados
void createEmpleado(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Empleados (idEmpleado, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2, "Maria");
    pstmt->setString(3, "Gomez");
    pstmt->setString(4, "123 Calle Falsa");
    pstmt->setString(5, "555-9876");
    pstmt->setString(6, "987654321");
    pstmt->setBoolean(7, 0);
    pstmt->setDateTime(8, "1980-01-01");
    pstmt->setInt(9, 1);
    pstmt->setDateTime(10, "2024-01-01");
    pstmt->setDateTime(11, "2024-06-01 10:00:00");
    pstmt->execute();
    delete pstmt;
}

void readEmpleados(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Empleados");
    while (res->next()) {
        std::cout << "ID Empleado: " << res->getInt("idEmpleado") << " ";
        std::cout << "Nombres: " << res->getString("nombres") << " ";
        std::cout << "Apellidos: " << res->getString("apellidos") << " ";
        std::cout << "Dirección: " << res->getString("direccion") << " ";
        std::cout << "Teléfono: " << res->getString("telefono") << " ";
        std::cout << "DPI: " << res->getString("DPI") << " ";
        std::cout << "Género: " << res->getBoolean("genero") << " ";
        std::cout << "Fecha Nacimiento: " << res->getString("fecha_nacimiento") << " ";
        std::cout << "ID Puesto: " << res->getInt("idPuesto") << " ";
        std::cout << "Fecha Inicio Labores: " << res->getString("fecha_inicio_labores") << " ";
        std::cout << "Fecha Ingreso: " << res->getString("fechaingreso") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateEmpleado(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Empleados SET direccion = ?, telefono = ? WHERE idEmpleado = ?");
    pstmt->setString(1, "456 Calle Real");
    pstmt->setString(2, "555-5678");
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteEmpleado(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Empleados WHERE idEmpleado = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Puestos
void createPuesto(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Puestos (idPuesto, puesto) VALUES (?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2, "Gerente");
    pstmt->execute();
    delete pstmt;
}

void readPuestos(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Puestos");
    while (res->next()) {
        std::cout << "ID Puesto: " << res->getInt("idPuesto") << " ";
        std::cout << "Puesto: " << res->getString("puesto") << std::endl;
    }
    delete res;
    delete stmt;
}

void updatePuesto(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Puestos SET puesto = ? WHERE idPuesto = ?");
    pstmt->setString(1, "Subgerente");
    pstmt->setInt(2, 1);
    pstmt->execute();
    delete pstmt;
}

void deletePuesto(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Puestos WHERE idPuesto = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Productos
void createProducto(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Productos (idProducto, producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2, "Producto A");
    pstmt->setInt(3, 1);
    pstmt->setString(4, "Descripción del producto A");
    pstmt->setString(5, "imagen_a.jpg");
    pstmt->setDouble(6, 10.00);
    pstmt->setDouble(7, 15.00);
    pstmt->setInt(8, 100);
    pstmt->setDateTime(9, "2024-06-01 10:00:00");
    pstmt->execute();
    delete pstmt;
}

void readProductos(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Productos");
    while (res->next()) {
        std::cout << "ID Producto: " << res->getInt("idProducto") << " ";
        std::cout << "Producto: " << res->getString("producto") << " ";
        std::cout << "ID Marca: " << res->getInt("idMarca") << " ";
        std::cout << "Descripción: " << res->getString("Descripcion") << " ";
        std::cout << "Imagen: " << res->getString("Imagen") << " ";
        std::cout << "Precio Costo: " << res->getDouble("precio_costo") << " ";
        std::cout << "Precio Venta: " << res->getDouble("precio_venta") << " ";
        std::cout << "Existencia: " << res->getInt("existencia") << " ";
        std::cout << "Fecha Ingreso: " << res->getString("fecha_ingreso") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateProducto(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Productos SET precio_venta = ?, existencia = ? WHERE idProducto = ?");
    pstmt->setDouble(1, 16.00);
    pstmt->setInt(2, 120);
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteProducto(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Productos WHERE idProducto = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Marcas
void createMarca(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Marcas (idmarca, marca) VALUES (?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2, "Marca A");
    pstmt->execute();
    delete pstmt;
}

void readMarcas(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Marcas");
    while (res->next()) {
        std::cout << "ID Marca: " << res->getInt("idmarca") << " ";
        std::cout << "Marca: " << res->getString("marca") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateMarca(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Marcas SET marca = ? WHERE idmarca = ?");
    pstmt->setString(1, "Marca B");
    pstmt->setInt(2, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteMarca(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Marcas WHERE idmarca = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Compras
void createCompra(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Compras (idcompra, no_orden_compra, idproveedor, fecha_orden, fechaingreso) VALUES (?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setInt(2, 2001);
    pstmt->setInt(3, 1);
    pstmt->setDateTime(4, "2024-06-01");
    pstmt->setDateTime(5, "2024-06-01 10:00:00");
    pstmt->execute();
    delete pstmt;
}

void readCompras(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Compras");
    while (res->next()) {
        std::cout << "ID Compra: " << res->getInt("idcompra") << " ";
        std::cout << "No. Orden Compra: " << res->getInt("no_orden_compra") << " ";
        std::cout << "ID Proveedor: " << res->getInt("idproveedor") << " ";
        std::cout << "Fecha Orden: " << res->getString("fecha_orden") << " ";
        std::cout << "Fecha Ingreso: " << res->getString("fechaingreso") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateCompra(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Compras SET no_orden_compra = ?, fecha_orden = ? WHERE idcompra = ?");
    pstmt->setInt(1, 2002);
    pstmt->setDateTime(2, "2024-06-02");
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteCompra(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Compras WHERE idcompra = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Proveedores
void createProveedor(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Proveedores (idProveedor, proveedor, nit, direccion, telefono) VALUES (?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2, "Proveedor A");
    pstmt->setString(3, "123456789");
    pstmt->setString(4, "789 Calle Comercio");
    pstmt->setString(5, "555-4321");
    pstmt->execute();
    delete pstmt;
}

void readProveedores(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Proveedores");
    while (res->next()) {
        std::cout << "ID Proveedor: " << res->getInt("idProveedor") << " ";
        std::cout << "Proveedor: " << res->getString("proveedor") << " ";
        std::cout << "NIT: " << res->getString("nit") << " ";
        std::cout << "Dirección: " << res->getString("direccion") << " ";
        std::cout << "Teléfono: " << res->getString("telefono") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateProveedor(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Proveedores SET proveedor = ?, telefono = ? WHERE idProveedor = ?");
    pstmt->setString(1, "Proveedor B");
    pstmt->setString(2, "555-6789");
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteProveedor(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Proveedores WHERE idProveedor = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Compras_detalle
void createCompraDetalle(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Compras_detalle (idcompra_detalle, idcompra, idproducto, cantidad, precio_costo_unitario) VALUES (?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setInt(2, 1);
    pstmt->setInt(3, 1);
    pstmt->setInt(4, 10);
    pstmt->setDouble(5, 10.00);
    pstmt->execute();
    delete pstmt;
}

void readComprasDetalle(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Compras_detalle");
    while (res->next()) {
        std::cout << "ID Compra Detalle: " << res->getInt("idcompra_detalle") << " ";
        std::cout << "ID Compra: " << res->getInt("idcompra") << " ";
        std::cout << "ID Producto: " << res->getInt("idproducto") << " ";
        std::cout << "Cantidad: " << res->getInt("cantidad") << " ";
        std::cout << "Precio Costo Unitario: " << res->getDouble("precio_costo_unitario") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateCompraDetalle(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Compras_detalle SET cantidad = ?, precio_costo_unitario = ? WHERE idcompra_detalle = ?");
    pstmt->setInt(1, 20);
    pstmt->setDouble(2, 11.00);
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteCompraDetalle(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Compras_detalle WHERE idcompra_detalle = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

// Ventas_detalle
void createVentaDetalle(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Ventas_detalle (idventa_detalle, idVenta, idProducto, cantidad, precio_unitario) VALUES (?, ?, ?, ?, ?)");
    pstmt->setInt(1, 1);
    pstmt->setInt(2, 1);
    pstmt->setInt(3, 1);
    pstmt->setInt(4, 5);
    pstmt->setDouble(5, 15.00);
    pstmt->execute();
    delete pstmt;
}

void readVentasDetalle(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Ventas_detalle");
    while (res->next()) {
        std::cout << "ID Venta Detalle: " << res->getInt("idventa_detalle") << " ";
        std::cout << "ID Venta: " << res->getInt("idVenta") << " ";
        std::cout << "ID Producto: " << res->getInt("idProducto") << " ";
        std::cout << "Cantidad: " << res->getInt("cantidad") << " ";
        std::cout << "Precio Unitario: " << res->getDouble("precio_unitario") << std::endl;
    }
    delete res;
    delete stmt;
}

void updateVentaDetalle(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Ventas_detalle SET cantidad = ?, precio_unitario = ? WHERE idventa_detalle = ?");
    pstmt->setInt(1, 10);
    pstmt->setDouble(2, 16.00);
    pstmt->setInt(3, 1);
    pstmt->execute();
    delete pstmt;
}

void deleteVentaDetalle(sql::Connection* con) {
    sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Ventas_detalle WHERE idventa_detalle = ?");
    pstmt->setInt(1, 1);
    pstmt->execute();
    delete pstmt;
}

int main() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("tcp://127.0.0.1:3306/mi_base_de_datos", "usuario", "contraseña");

        // CRUD para Clientes
        createCliente(con);
        readClientes(con);
        updateCliente(con);
        deleteCliente(con);

        // CRUD para Ventas
        createVenta(con);
        readVentas(con);
        updateVenta(con);
        deleteVenta(con);

        // CRUD para Empleados
        createEmpleado(con);
        readEmpleados(con);
        updateEmpleado(con);
        deleteEmpleado(con);

        // CRUD para Puestos
        createPuesto(con);
        readPuestos(con);
        updatePuesto(con);
        deletePuesto(con);

        // CRUD para Productos
        createProducto(con);
        readProductos(con);
        updateProducto(con);
        deleteProducto(con);

        // CRUD para Marcas
        createMarca(con);
        readMarcas(con);
        updateMarca(con);
        deleteMarca(con);

        // CRUD para Compras
        createCompra(con);
        readCompras(con);
        updateCompra(con);
        deleteCompra(con);

        // CRUD para Proveedores
        createProveedor(con);
        readProveedores(con);
        updateProveedor(con);
        deleteProveedor(con);

        // CRUD para Compras_detalle
        createCompraDetalle(con);
        readComprasDetalle(con);
        updateCompraDetalle(con);
        deleteCompraDetalle(con);

        // CRUD para Ventas_detalle
        createVentaDetalle(con);
        readVentasDetalle(con);
        updateVentaDetalle(con);
        deleteVentaDetalle(con);

        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

