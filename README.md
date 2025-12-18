# 🧾 Sistema de Gestión de Clientes, Artículos y Facturación

Proyecto desarrollado en **lenguaje C** como trabajo práctico de la materia **Estructura y Base de Datos** (2º año de la carrera).

---

## 📖 Descripción del proyecto

Este sistema permite gestionar **clientes, artículos y procesos de facturación**, aplicando conceptos fundamentales de programación en C, manejo de archivos binarios y persistencia de datos.

El programa posibilita registrar clientes y artículos, realizar facturaciones, actualizar stock, generar estadísticas y mostrar datos ordenados, manteniendo la consistencia de la información entre múltiples archivos.

Si bien algunas decisiones de diseño (como el uso de archivos binarios) estaban establecidas por los requisitos académicos, el proyecto fue clave para afianzar el manejo de **datos persistentes**, la **interacción controlada entre archivos** y la **lógica de negocio aplicada a un sistema realista**.

---

## 💡 Funcionalidades principales

- 📂 **Mostrar clientes y artículos**  
  Visualización de los registros almacenados en archivos binarios.

- ➕ **Alta de clientes y artículos**  
  Creación de nuevos registros con actualización inmediata de los archivos correspondientes.

- 🧾 **Facturación**  
  Registro de ventas de artículos a clientes, con:
  - actualización de stock  
  - actualización del saldo del cliente  
  - almacenamiento del historial de facturas en archivo binario

- 📊 **Estadísticas**  
  Identificación del producto estrella en base al monto total facturado.

- 🔢 **Listado ordenado de clientes**  
  Generación de un listado alfabético por nombre.

- 💾 **Persistencia de datos**  
  Todos los datos se almacenan en archivos binarios (`.dat`) para ser reutilizados en futuras ejecuciones.

---

## ⚙️ Desafío técnico destacado

La funcionalidad de **facturación** fue el aspecto más desafiante del proyecto, ya que requiere:

- Manejo simultáneo de **tres archivos binarios** (clientes, artículos y facturas)
- Validación de existencia de registros
- Control de stock disponible
- Actualización consistente de datos ya existentes en archivos
- Escritura y reescritura selectiva de registros mediante `fseek`

Este proceso permitió profundizar en la **consistencia de datos** y en la correcta coordinación de múltiples fuentes de información.

---

## 🛠 Tecnologías y conceptos aplicados

- **Lenguaje C**
  - Uso de `struct`
  - Archivos binarios (`fread`, `fwrite`, `fseek`, `fflush`)
  - Validación de entradas
  - Control de errores

- **Estructuras de datos**
  - `Cliente_t`
  - `Articulo_t`
  - `Factura_t`

- **Validaciones clave**
  - Apertura y creación segura de archivos
  - Existencia de clientes y artículos antes de operar
  - Control de stock al facturar
  - Actualización consistente de registros

---

## 📘 Aprendizajes clave

- Manejo avanzado de archivos binarios en C
- Reescritura controlada de registros específicos
- Diseño de lógica de negocio aplicada a facturación
- Coordinación de múltiples archivos dentro de un flujo lógico
- Organización y modularización del código

---

## 🚀 Posibles mejoras futuras

- Implementar memoria dinámica para optimizar recursos
- Agregar autenticación de usuarios y control de permisos
- Incorporar reportes detallados de facturación por cliente o artículo
- Exportación de datos a formatos legibles (`.txt` / `.csv`)
- Separación del proyecto en módulos para mejorar escalabilidad

---

## 👩‍💻 Autora

**Carla Sofía Corvalán Portillo**  
Docente técnica y estudiante de Tecnicatura Superior en Informática  
Interesada en desarrollarse profesionalmente en el ámbito IT, especialmente en áreas de backend, bases de datos y sistemas.

---

## 🎓 Contexto académico

Trabajo práctico realizado para la materia **Estructura y Base de Datos**  
Universidad Tecnológica Nacional – INSPT
