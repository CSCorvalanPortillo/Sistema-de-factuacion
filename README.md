🧾 Sistema de Gestión de Clientes, Artículos y Facturación
📖 Descripción

Este proyecto es un sistema de gestión de clientes, artículos y facturación, desarrollado en C como trabajo práctico de la materia Estructura y Base de Datos (2º año de la carrera).
El programa permite registrar clientes y artículos, realizar facturaciones, generar estadísticas y mostrar datos ordenados.

Aunque algunas decisiones, como el uso de archivos binarios, venían indicadas por los requisitos de la materia, este proyecto me permitió aprender a manejar datos persistentes, archivos binarios y estructuras en C, así como interactuar con múltiples archivos al mismo tiempo de manera controlada.

💡 Funcionalidades

📂 Mostrar Clientes y Artículos: Visualiza los registros guardados en archivos binarios.

➕ Agregar Cliente o Artículo: Permite crear nuevos registros, actualizando los archivos correspondientes.

🧾 Facturación: Registra la venta de artículos a clientes, actualiza stock y saldo del cliente, y guarda un historial en un archivo de facturas.

📊 Estadísticas: Muestra el producto estrella basado en el monto total facturado.

🔢 Ordenar y mostrar clientes: Genera un listado de clientes ordenados alfabéticamente por nombre.

💾 Persistencia: Todos los datos se guardan en archivos binarios (.dat) para poder reutilizarlos en futuras ejecuciones.

La función facturar fue la más desafiante, ya que implica manejar tres archivos simultáneamente y asegurar la consistencia de datos, especialmente cuando se actualiza stock o se registra el saldo del cliente.

🛠 Tecnologías y conceptos aplicados

Lenguaje C: uso de struct, manejo de archivos binarios (fread, fwrite, fseek, fflush), validación de entradas y control de errores.

Estructuras: Cliente_t, Articulo_t y Factura_t organizan los datos del sistema, facilitando consultas y actualizaciones.

Validaciones clave:

Apertura y creación de archivos.

Existencia de clientes y artículos antes de operar.

Cantidad suficiente de stock al facturar.

Aprendizaje clave:

Manejo avanzado de archivos binarios y manipulación de campos de texto.

Recorriendo archivos para sobreescribir datos específicos y mantener consistencia.

Integración de múltiples archivos en un flujo lógico de operaciones.

🚀 Mejoras posibles

Implementar memoria dinámica para optimizar uso de recursos y tiempos de ejecución.

Agregar autenticación de usuarios o control de permisos para proteger los archivos.

Incorporar reportes detallados de facturación por cliente o por artículo.

Posibilidad de exportar datos a formato legible (.txt o .csv) para informes externos.