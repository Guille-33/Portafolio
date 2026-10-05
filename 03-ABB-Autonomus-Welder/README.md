# 🤖 ABB Autonomous Welder (RobotStudio & RAPID)

### 🌍 Language Selection / Selección de Idioma
* 🇪🇸 [Versión en Español](#-versión-en-español)
* 🇺🇸 [English Version](#-english-version)

---

# 🇪🇸 Versión en Español

## 🎯 El Reto Técnico
El objetivo de este proyecto fue diseñar e implementar una **célula robótica automatizada interactiva** en ABB RobotStudio para resolver un cuello de botella industrial: el ensamblaje y la soldadura de bisagras en cajas metálicas de alta seguridad. 

El sistema debía ser capaz de identificar de manera inteligente y en tiempo real el tamaño de las cajas que llegaban de forma aleatoria por una cinta transportadora, adaptando las trayectorias de posicionamiento y soldadura de forma dinámica.

## ⚙️ Arquitectura del Sistema y Modelos de Robots
La célula robótica utiliza una configuración de **dos robots especializados (Multi-Robot System)** coordinados en tiempo real:
1. **Robot de Manipulación (ABB IRB 1200-5/0.9):** Un robot compacto de 6 grados de libertad (DOF), carga útil de 5 kg y alcance de 0.9 m. Se encarga de la manipulación de las cajas, la recogida de bisagras usando una pinza de vacío personalizada y la clasificación final por tamaños.
2. **Robot de Soldadura (ABB IRB 1600-6/1.20):** Con 6 kg de carga útil y un alcance extendido de 1.2 m, optimizado para gestionar el paquete de cables de soldadura y ejecutar trayectorias complejas con la antorcha.

## 🧠 Conceptos Avanzados de RAPID e Ingeniería
* **Sincronización mediante I/O Digitales:** Implementación de protocolos de comunicación en tiempo real (`SetDO` y `WaitDI`) para gestionar el intercambio de estados entre ambos robots, asegurando que el robot de soldadura actúe solo cuando el espacio esté despejado.
* **Calibración de WorkObjects (`wobjdata`) y TCP:** Creación de marcos de coordenadas locales (`Wobj_cajag` y `Wobj_cajap`) en las esquinas de las cajas. Las trayectorias se calculan matemáticamente usando funciones `Offs` (Offsets) en lugar de puntos fijos, facilitando el reajuste del sistema.
* **Flujo No Lineal y Modularidad:** Uso de rutinas con paso de parámetros (`PROC Coger_Caja(robtarget pos, num tipo)`) y funciones personalizadas (`FUNC robtarget ObtenerPosicionCaja`) para reciclar código según las dimensiones del objetivo.
* **Interrupciones de Seguridad (Rutinas TRAP):** Programación de un botón de parada de emergencia ("Seta Roja") mapeado mediante señales que detiene inmediatamente el movimiento de ambos robots mediante instrucciones `StopMove`.
* **Smart Components de RobotStudio:** Uso de lógica avanzada de estación (`Source`, `Attacher`, `Detacher` y un componente personalizado de unión `Union`) para simular de forma fidedigna el comportamiento físico del metal soldado.

## 🛠️ Configuración y Ejecución
1. Descarga e instala **ABB RobotStudio** (versión 6.x o superior).
2. Abre la estación empaquetada o importa los módulos de código RAPID situados en la carpeta `/src`.
3. Sincroniza las trayectorias con el controlador virtual.
4. Abre la lógica de la cinta transportadora (*Conveyor Properties*) y pulsa **"start or resume"** para iniciar el flujo aleatorio de cajas y comenzar la simulación.

*Nota: Puedes consultar la memoria de ingeniería completa en el archivo adjunto [Report_Project_ABB.pdf](./Report_Project_ABB.pdf) dentro de esta carpeta.*

---

# 🇺🇸 English Version

## 🎯 Technical Challenge
The goal of this project was to design and implement an **interactive automated robotic cell** within ABB RobotStudio to solve a real-world manufacturing bottleneck: the alignment and welding of industrial hinges onto high-security metal boxes. 

The system needed to intelligently identify the size of incoming boxes arriving randomly on a conveyor belt, adjusting the handling and welding paths dynamically in real-time.

## ⚙️ System Architecture & Robot Selection
The robotic cell features a **two-robot coordinated setup (Multi-Robot System)** communicating in real-time:
1. **Handling Robot (ABB IRB 1200-5/0.9):** A 6 DOF compact manipulator with a 5 kg payload and 0.9 m reach. It manages the box sorting, picks up the hinges using a custom vacuum gripper, and handles final stacking based on size.
2. **Welding Robot (ABB IRB 1600-6/1.20):** Featuring a 6 kg payload and an extended 1.2 m reach, optimized to handle the bulky welding torch cable package and execute precise trajectories.

## 🧠 Advanced RAPID & Software Engineering Concepts
* **Inter-Robot Synchronization:** Deployed real-time digital communication signals (`SetDO` and `WaitDI`) to manage the interlocking handoff protocol between the handling and welding phases safely.
* **WorkObjects (`wobjdata`) & TCP Calibration:** Defined local coordinate systems (`Wobj_cajag` and `Wobj_cajap`) positioned at the box corners. All picking and welding paths are mathematically computed via `Offs` (Offset) transformations relative to these frames for seamless adjustments.
* **Non-Linear Flow & Modularity:** Programmed parameterized procedures (`PROC Coger_Caja(robtarget pos, num tipo)`) and custom functions (`FUNC robtarget ObtenerPosicionCaja`) to dynamically determine tool vectors without duplicating code.
* **Safety Interrupts (TRAP Routines):** Engineered a global emergency stop sequence linked to a virtual digital input. When forced, it triggers a background RAPID event intercept (`TRAP`), executing a deterministic `StopMove` across both controllers simultaneously.
* **RobotStudio Smart Components:** Integrated advanced station events (`Source`, `Attacher`, `Detacher`, and a custom `Union` merge mechanic) to simulate realistic tool interactions and permanent material transformations.

## 🛠️ Simulation Setup
1. Launch **ABB RobotStudio** (version 6.x or higher recommended).
2. Load the station pack or import the RAPID program modules located in the `/src` directory.
3. Synchronize the paths to the virtual station controllers.
4. Open the conveyor simulation properties panel, trigger the **"start or resume"** digital flag, and observe the autonomous multi-robot sequence.

*Note: For a detailed engineering breakdown, you can read our full project report available in the [Report_Project_ABB.pdf](./Report_Project_ABB.pdf) file located inside this directory.*
