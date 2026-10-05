# ⚡ Circuit Mesh Resolver (MATLAB)

### 🌍 Language Selection / Selección de Idioma
* 🇪🇸 [Versión en Español](#-versión-en-español)
* 🇺🇸 [English Version](#-english-version)

---

# 🇪🇸 Versión en Español

## 🎯 El Reto Técnico
El objetivo consistía en mapear y resolver redes eléctricas complejas mediante programación, sin depender de suites externas de simulación electrónica. El sistema convierte los datos de interconectividad de un esquema directamente en ecuaciones matemáticas formales.

## 🧠 Conceptos Clave de Ingeniería
* **Modelado Matricial:** Traduce automáticamente las ramas y nodos del circuito en un sistema lineal unificado (\(A \cdot x = B\)) aplicando las Leyes de Corrientes y Tensiones de Kirchhoff.
* **Eficiencia Numérica:** Emplea las técnicas nativas de factorización matricial de MATLAB (como el operador barra invertida `\`) para realizar una resolución segura y veloz de las distribuciones de corriente.

## 🛠️ Cómo Ejecutar
1. Inicia **MATLAB**.
2. Cambia el directorio de trabajo a `/01-Cirtuit-Resolver/src`.
3. Abre y ejecuta el script principal (ej. `main.m`).
4. Introduce los parámetros de configuración de tu circuito en la Ventana de Comandos cuando el programa lo solicite.

---

# 🇺🇸 English Version

## 🎯 Technical Challenge
The goal was to programmatically map and solve multi-mesh electrical networks without third-party electronic simulation suites. The system converts schematic interconnectivity data directly into formal mathematical equations.

## 🧠 Core Engineering Concepts
* **Matrix Engineering:** Automatically translates circuit branches and nodes into a unified linear system (\(A \cdot x = B\)) using Kirchhoff's Current and Voltage Laws.
* **Numerical Efficiency:** Employs MATLAB's native matrix factorization techniques (such as the backslash operator `\`) to perform safe, high-speed resolution of network branch distributions.

## 🛠️ How to Run
1. Launch **MATLAB**.
2. Set the working directory to `/01-Cirtuit-Resolver/src`.
3. Open and run the primary script (e.g., `main.m`).
4. Input your circuit configuration parameters directly in the Command Window when prompted.
