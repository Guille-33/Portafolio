# ❌ Dynamic N×N Tic-Tac-Toe (C++)

### 🌍 Language Selection / Selección de Idioma
* 🇪🇸 [Versión en Español](#-versión-en-español)
* 🇺🇸 [English Version](#-english-version)

---

# 🇪🇸 Versión en Español

## 🎯 El Reto Técnico
La mayoría de los juegos de tablero por consola sufren de barreras de tamaño fijo (ej. matrices rígidas de 3x3). Este proyecto elimina esas limitaciones, permitiendo que el tablero escale dinámicamente a cualquier tamaño N × N introducido por el usuario en tiempo de ejecución, manteniendo un control estricto contra fugas de memoria.

## 🧠 Conceptos Clave de Ingeniería
* **Asignación Dinámica de Memoria:** Reserva las dimensiones de la matriz multidimensional en tiempo de ejecución mediante punteros tradicionales (`new[][]`). Asegura una desasignación de memoria determinista (`delete[]`) al finalizar la ejecución.
* **Condiciones de Victoria Genéricas:** Reemplaza las comprobaciones estáticas por algoritmos parametrizados capaces de evaluar líneas diagonales, horizontales y verticales de forma fluida en tableros escalables.

## 🛠️ Cómo Compilar y Ejecutar

### Opción 1: Consola de Comandos (Linux / Windows con g++)
1. Navega a la carpeta de origen:
   ```bash
   cd 02-Dynamic-TIC-TAC-TOE/src
   ```
2. Compila el binario:
   ```bash
   g++ -std=c++17 main.cpp -o dynamic_ttt
   ```
3. Ejecuta:
   ```bash
   ./dynamic_ttt
   ```

### Opción 2: IDE Dev-C++ (Windows)
1. Abre **Dev-C++** y carga los archivos fuente de la carpeta `src/`.
2. Asegúrate de tener seleccionado un perfil de C++11 o superior en la configuración del compilador.
3. Presiona **F11** para compilar y ejecutar.

---

# 🇺🇸 English Version

## 🎯 Technical Challenge
Most terminal grid games suffer from hardcoded size barriers (e.g., fixed 3x3 matrices). This project removes those barriers, allowing the board to scale up dynamically to any custom N × N size input by the user while maintaining rigid safety loops against memory leaks.

## 🧠 Core Engineering Concepts
* **Dynamic Memory Arrays:** Allocates dynamic multi-dimensional matrix dimensions at runtime using standard pointer allocation (`new[][]`). Ensure deterministic memory deallocation (`delete[]`) upon termination.
* **Generic Win Conditions:** Replaced hardcoded checks with dynamic parameterized algorithms capable of evaluating diagonal, horizontal, and vertical matrix lines seamlessly on scalable boards.

## 🛠️ How to Compile & Run

### Option 1: Linux / Windows Command Line (g++)
1. Navigate to the source folder:
   ```bash
   cd 02-Dynamic-TIC-TAC-TOE/src
   ```
2. Compile the binary:
   ```bash
   g++ -std=c++17 main.cpp -o dynamic_ttt
   ```
3. Run:
   ```bash
   ./dynamic_ttt
   ```

### Option 2: Dev-C++ IDE (Windows)
1. Launch **Dev-C++** and open the source files.
2. Ensure you have selected a C++11 or higher profile in compiler configuration.
3. Hit **F11** to build and run the executable.
