# RPG Combat System / Sistema de Combate RPG

Choose your language / Selecciona tu idioma:
* [🇪🇸 Versión en Español](#-versión-en-español)
* [🇺🇸 English Version](#-english-version)

---

# 🇪🇸 Versión en Español

Sistema de Combate RPG

El proyecto consiste en un videojuego de combate por turnos basado en equipos (Team vs Team), implementado en **C++** utilizando conceptos avanzados de **Programación Orientada a Objetos (POO)** y las estructuras de datos de la **STL**.

## 🚀 Características Principales

* **Combate por Turnos por Equipos:** Gestión dinámica de enfrentamientos de equipo contra equipo en lugar de duelos individuales.
* **Persistencia de Datos (Archivos):** Sistema automatizado para guardar y cargar el progreso de la partida, los equipos activos y el estado del cementerio (`Graveyard`) sin sobreescribir archivos gracias al formateo por tiempo del sistema.
* **Registro de Acciones (Action Log):** Generación en tiempo real de un historial de combate exportado a un archivo `.txt` y accesible desde el propio juego.
* **Sistema de Progresión y Experiencia:** Los personajes ganan puntos de experiencia (XP) equivalentes al daño infligido, permitiéndoles subir de nivel y mejorar sus atributos de manera automática.
* **Economía e Inventario:** Mecánicas de compra y venta de equipamiento adaptadas a cada clase, con devaluación de precios al vender armas y almacenamiento optimizado de consumibles.
* **Mejoras Estéticas:** Interfaz de consola optimizada mediante menús interactivos y textos coloreados según la rareza del equipamiento.

---

## 📐 Evolución de la Arquitectura (Diseño de Clases)

El diseño del software evolucionó significativamente desde su concepción inicial hasta la versión definitiva:

1. **Primera Entrega:** Una estructura básica donde la lógica de control residía casi por completo en el archivo `main.cpp`. Las armas, hechizos y pociones se gestionaban únicamente como variables de tipo entero (`int`) dentro de los personajes.
2. **Versión Final:** Migración hacia un diseño totalmente orientado a objetos. Los elementos del juego pasaron a ser clases independientes (`Weapon`, `Potions`, `Spells`) y el control del flujo del programa se delegó en una clase maestra coordinadora llamada `Game`. Se implementó un uso intensivo de contenedores de la STL como `std::vector` (incluyendo matrices bidimensionales) y `std::deque`.

### Relaciones del Modelo de Clases:
* **Composición:** Utilizada en clases que poseen estrictamente a otras, como `Character` e `Inventory`.
* **Agregación:** Utilizada cuando una clase contiene colecciones de punteros a otras, como `Game` almacenando instancias de `Character*`.
* **Polimorfismo (Público):** La clase abstracta base `Character` define el comportamiento general, mientras que las clases derivadas `Warrior`, `Archer` y `Mage` especializan sus atributos y mecánicas de ataque/defensa.

---

## 🗂️ Estructura de Clases e Implementación

### 1. `Character` (Clase Base Abstracta)
Contiene los atributos compartidos por todos los héroes (salud, precisión, protección, poder, nombre, nivel y experiencia). 
* **Optimización Clave:** El método abstracto puro no es el de visualización (`display`), sino una función llamada `statsXp()`. Esto permite actualizar los atributos específicos de cada subclase al subir de nivel y renderizar al personaje de forma polimórfica sin necesidad de realizar costosos castings dinámicos (`dynamic_cast`) en los bucles de renderizado.
* **Creación Flexible:** Permite instanciar personajes predefinidos de Nivel 1 mediante sobrecarga de constructores o parametrizar todas sus estadísticas a mano.

### 2. Clases Hijas (`Warrior`, `Archer`, `Mage`)
Especializan al personaje y calculan en tiempo real los atributos variables de ataque y defensa en función de las armas que lleven equipadas.
* **Gestión de Memoria:** Para evitar copias innecesarias en memoria, las armas equipadas o guardadas en el inventario son referencias directas a los objetos originales generados por la tienda. Cualquier modificación en el objeto de la tienda se refleja con seguridad en todo el sistema.
* `Mage`: Clase exclusiva capaz de utilizar la mecánica de hechizos (`Spells`) gastando puntos de maná. Los estados alterados aplicados por los hechizos tienen una penalización de balanceo y duran exactamente un turno.

### 3. `Inventory` y `Store`
* `Inventory`: Actúa como puente de almacenamiento para el personaje, custodiando un `std::deque` de armas, el objeto de pociones, las flechas (en caso del arquero) y el dinero disponible.
* `Store`: Se encarga de instanciar el catálogo completo de armas y consumibles. Está programada para auto-adaptarse dinámicamente al tipo de personaje que la consulta, mostrando únicamente los objetos que esa clase específica tiene permitido adquirir.

### 4. `Game` (Núcleo del Sistema)
Es la clase con mayor peso de lógica. Gobierna de manera centralizada la ejecución del programa: controla el flujo de los turnos, gestiona los equipos mediante vectores bidimensionales de punteros, administra a los personajes caídos en combate (`_Graveyard`) mediante deques, y canaliza los métodos de serialización de archivos.

---

## 📊 Equilibrio de Equipamiento y Sistema de Niveles

### Tabla de Progresión de Armas

| Tipo de Arma | Común (Lvl 1) | Poco Común (Lvl 2) | Raro (Lvl 3) | Épico (Lvl 4) | Legendario (Lvl 5) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Espada** *(Sword)* | Daño: 6<br>Compra: 7 / Venta: 5 | Daño: 12<br>Compra: 10 / Venta: 7 | Daño: 18<br>Compra: 25 / Venta: 15 | Daño: 24<br>Compra: 40 / Venta: 25<br>*Extra: +1/2 XP* | Daño: 30<br>Compra: 50 / Venta: 50<br>*Extra: +1/2 Oro obtenido* |
| **Maza** *(Maze)* | Daño: 10<br>Compra: 7 / Venta: 5 | Daño: 20<br>Compra: 10 / Venta: 7 | Daño: 30<br>Compra: 25 / Venta: 15 | Daño: 40<br>Compra: 40 / Venta: 25<br>*Extra: +0.25 Precisión* | Daño: 50<br>Compra: 50 / Venta: 50<br>*Extra: +0.5 Precisión* |
| **Arco** *(Bow)* | Daño: 10<br>Compra: 10 / Venta: 7 | Daño: 25<br>Compra: 20 / Venta: 10 | Daño: 40<br>Compra: 30 / Venta: 15 | Daño: 55<br>Compra: 40 / Venta: 20<br>*Extra: Prob. de reducir ataque enemigo* | Daño: 70<br>Compra: 70 / Venta: 70<br>*Extra: Flechas infinitas* |

| Tipo de Báculo *(Staff)* | Básico | Agua *(Water)* | Aire *(Air)* | Tierra *(Earth)* | Fuego *(Fire)* |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Estadísticas** | Daño: 20<br>Compra: 20<br>Venta: 20 | Daño: 40<br>Compra: 60<br>Venta: 30 | Daño: 25<br>Compra: 60<br>Venta: 30<br>*Extra: Rompe escudo y quita 0.25 maná* | Daño: 30<br>Compra: 60<br>Venta: 30<br>*Extra: Ignora la mitad de la protección* | Daño: 20<br>Compra: 60<br>Venta: 30<br>*Extra: Potencia hechizos de fuego* |

---

## 🚀 Instalación y Compilación (Ubuntu)

Este proyecto es un juego RPG en C++ desarrollado en **Ubuntu** utilizando el framework **Qt**. Sigue estos pasos para instalar las dependencias necesarias y compilarlo desde la terminal.

### 📋 Requisitos Previos

Necesitas instalar las herramientas de compilación esenciales, el compilador de C++ (`g++`) y las herramientas de desarrollo de Qt (`qmake`). Abre una terminal y ejecuta:

```bash
sudo apt update
sudo apt install build-essential qtcreator qtbase5-dev qt5-qmake
```

### 🛠️ Pasos para Compilar y Ejecutar

1. **Clonar el repositorio:**
   ```bash
   git clone https://github.com
   cd RPG-Combar-System/src
   ```

2. **Generar el Makefile con qmake:**
   `qmake` leerá el archivo `trabajo.pro` para configurar la compilación de forma automática.
   ```bash
   qmake trabajo.pro
   ```

3. **Compilar el proyecto:**
   Usa el comando `make` para compilar los archivos fuente (`.cpp`). Puedes usar `-j$(nproc)` para acelerar el proceso usando todos los núcleos de tu procesador.
   ```bash
   make -j$(nproc)
   ```

4. **Ejecutar el juego:**
   Una vez finalizada la compilación, se generará el archivo ejecutable. Ejecútalo con el siguiente comando:
   ```bash
   ./trabajo
   ```

---

### 💻 Alternativa: Abrir con Qt Creator (Interfaz Gráfica)

Si prefieres trabajar con un entorno visual:
1. Abre **Qt Creator**.
2. Ve a **File > Open File or Project...** y selecciona el archivo `trabajo.pro`.
3. Configura el *Kit* predeterminado que te sugiera el programa.
4. Pulsa el botón verde **Run** (o presiona `Ctrl + R`) para compilar y lanzar el juego.


*Nota: Durante el juego, se puede introducir el código numérico oculto `69` en los menús de selección para desplegar inmediatamente la visualización completa del Action Log en la consola.*

---
---

# 🇺🇸 English Version

RPG Combat System

The project consists of a turn-based, team-vs-team RPG combat video game implemented in **C++** utilizing advanced **Object-Oriented Programming (OOP)** concepts and **STL** data structures.

## 🚀 Key Features

* **Team-vs-Team Turn-Based Combat:** Centralized gameplay mechanics tailored for entire team matchups rather than standard 1v1 duels.
* **File Management & Persistence:** Automatic save/load system for active gameplay progress, team rosters, and the deceased character queue (`Graveyard`), safely timestamped with system time to prevent file overwrites.
* **Action Logging:** Real-time generation of an exportable `.txt` battle history log, which can also be inspected live directly inside the game console.
* **Experience & Progression System:** Characters gain experience points (XP) equivalent to the exact damage they inflict on opponents, unlocking automatic level-ups and statistical growth.
* **Economy & Inventory management:** Class-restricted buy/sell store loops featuring item-devaluation mechanics on weapon sales and optimized potion tracking.
* **Aesthetic Enhancements:** Terminal user interface enhanced with interactive menus and color-coded text outputs mapped to item rarity grades.

---

## 📐 Architecture Evolution (Class Design)

The codebase's design went through a major transformation from initial planning to final release:

1. **First Delivery:** A basic footprint where the main core loop lived entirely within `main.cpp`. Supporting entities like weapons, spells, and potions were tracked solely as flat `int` variables tied inside character fields.
2. **Final Version:** A deep migration toward full Object-Oriented design. Virtual assets were abstracted into modular classes (`Weapon`, `Potions`, `Spells`), and overall program coordination was decoupled into a master controller class named `Game`. The engine leverages standard STL containers including `std::vector` (with matrix structures) and `std::deque`.

### Architectural Relationships:
* **Composition:** Enforced on objects with strict ownership bounds, such as `Character` possessing an `Inventory`.
* **Aggregation:** Handled when a class holds standard runtime collections of pointers, such as `Game` managing sets of `Character*`.
* **Polymorphism (Public):** The abstract base class `Character` handles the unified interface blueprint, while the derived subclasses `Warrior`, `Archer`, and `Mage` implement class-specific stats and combat routines.

---

## 🗂️ Class Breakdown & Implementation

### 1. `Character` (Abstract Base Class)
Manages the universal attributes shared by every unit (health, accuracy, protection, power, name, level, and XP).
* **Key Optimization:** Instead of marking the rendering `display` routine as the pure virtual method, the abstract requirement was placed on a stat-scaling method called `statsXp()`. This enables derived classes to compute their customized stat scaling during level-ups, allowing polimorphic display calls to run natively without requiring overhead-heavy `dynamic_cast` calls during loop steps.
* **Flexible Creation:** Supports quick-instancing level-1 archetypes via constructor overloading as well as manually custom-crafting fine-tuned statistics field-by-field.

### 2. Subclasses (`Warrior`, `Archer`, `Mage`)
Specialize base characters and compute reactive attack/defense scores on the fly depending on currently equipped items.
* **Memory Management:** To avoid creating bloated duplicate copies in memory, all weapons held in an inventory or equipped on a character are references pointing directly to the base store's catalog objects. Any adjustments on weapon metrics cascade cleanly through the entire environment.
* `Mage`: The unique archetype capable of casting resource-draining `Spells` at the expense of mana points. Spell-inflicted debuffs scale with a turn-cost balance penalty and expire after exactly one turn.

### 3. `Inventory` & `Store`
* `Inventory`: Serves as a data bridge for the hero, storing a `std::deque` of weapons, the potion bundle object, arrows (for the archer class), and gold balances.
* `Store`: Handles the base factory instantiation of weapons and items. It is programmed to adapt its contents dynamically to the querying class, displaying only items relevant to that specific hero type.

### 4. `Game` (Core Orchestrator)
The heaviest structural component of the project. It acts as the centralized manager governing state flow, turn tracking, matrix-backed multi-team structures, dead player preservation via the `_Graveyard` deque, and file serialization routines.

---

## 📊 Equipment Balancing & Level Progression

### Weapon Tier Metrics

The game implements a tier-progression matrix determining weapon effectiveness, market cost, and custom attributes:

| Weapon Type | Common (Lvl 1) | Uncommon (Lvl 2) | Rare (Lvl 3) | Epic (Lvl 4) | Legendary (Lvl 5) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Sword** | Power: 6<br>Buy: 7 / Sell: 5 | Power: 12<br>Buy: 10 / Sell: 7 | Power: 18<br>Buy: 25 / Sell: 15 | Power: 24<br>Buy: 40 / Sell: 25<br>*Extra: +1/2 XP gain* | Power: 30<br>Buy: 50 / Sell: 50<br>*Extra: +1/2 Gold gain* |
| **Mace** | Power: 10<br>Buy: 7 / Sell: 5 | Power: 20<br>Buy: 10 / Sell: 7 | Power: 30<br>Buy: 25 / Sell: 15 | Power: 40<br>Buy: 40 / Sell: 25<br>*Extra: +0.25 Accuracy* | Power: 50<br>Buy: 50 / Sell: 50<br>*Extra: +0.5 Accuracy* |
| **Bow** | Power: 10<br>Buy: 10 / Sell: 7 | Power: 25<br>Buy: 20 / Sell: 10 | Power: 40<br>Buy: 30 / Sell: 15 | Power: 55<br>Buy: 40 / Sell: 20<br>*Extra: Chance to lower enemy attack* | Power: 70<br>Buy: 70 / Sell: 70<br>*Extra: Infinite arrows* |

| Staff Type | Basic | Water | Air | Earth | Fire |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Stats & Modifiers** | Power: 20<br>Buy: 20<br>Sell: 20 | Power: 40<br>Buy: 60<br>Sell: 30 | Power: 25<br>Buy: 60<br>Sell: 30<br>*Extra: Destroys shield & siphons 0.25 mana* | Power: 30<br>Buy: 60<br>Sell: 30<br>*Extra: Pierces half of target protection* | Power: 20<br>Buy: 60<br>Sell: 30<br>*Extra: Buffs active fire spells* |

---

## 🚀 Installation and Compilation (Ubuntu)

This project is a C++ RPG game developed on **Ubuntu** using the **Qt** framework. Follow these steps to install the necessary dependencies and compile the game from your terminal.

### 📋 Prerequisites & Dependencies

Unlike other languages that use dependency files (like `requirements.txt` in Python), C++ projects on Linux manage dependencies directly through the system's package manager (`apt`). 

This project relies on **Qt5** for its core structure and build system, along with standard C++ libraries. Open your terminal and run the following command to install everything required:

```bash
sudo apt update
sudo apt install build-essential qtcreator qtbase5-dev qt5-qmake
```

**Libraries used in this project:**
*   **C++ Standard Template Library (STL):** `<vector>`, `<string>`, `<deque>`, `<iostream>`, `<fstream>` (Included by default with the `g++` compiler).
*   **Qt Core / Qt Base:** Required to process the `trabajo.pro` project file and handle compilation.

---

### 🛠️ Compiling and Running via Terminal

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd RPG-Combat-System/src
   ```

2. **Generate the Makefile using qmake:**
   `qmake` will read the `trabajo.pro` file to configure the build automatically.
   ```bash
   qmake trabajo.pro
   ```

3. **Compile the project:**
   Use the `make` command to compile the source code. You can add `-j$(nproc)` to speed up the process by using all available CPU cores.
   ```bash
   make -j$(nproc)
   ```

4. **Run the game:**
   Once the compilation finishes, an executable binary will be generated. Run it using:
   ```bash
   ./trabajo
   ```

---

### 💻 Alternative: Open with Qt Creator (GUI)

If you prefer using a visual development environment:
1. Open **Qt Creator**.
2. Go to **File > Open File or Project...** and select the `trabajo.pro` file.
3. Configure the default *Kit* suggested by the IDE.
4. Click the green **Run** button (or press `Ctrl + R`) to compile and launch the game.


*Tip: While playing, typing the hidden numeric sequence `69` during a menu selection screen will immediately output the full runtime Action Log contents directly onto the console screen.*
