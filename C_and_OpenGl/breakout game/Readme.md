# 🎮 Breakout Game – OpenGL & GLUT Edition

A colorful and interactive implementation of the classic Breakout game using **OpenGL** and **GLUT**, designed and developed in **Xcode (macOS)** with compatibility on **Windows (Code::Blocks)**. Players control a paddle to bounce a ball and break bricks, with difficulty modes that dynamically affect gameplay visuals and mechanics.

---

## 🚀 Features

- 🧱 Brick-breaking gameplay with a responsive paddle and bouncing ball.
- 🎨 Easy and Hard difficulty modes with distinct backgrounds and color themes.
- ⏱️ Real-time timer and score tracking displayed in-game.
- 💥 Game result popups with animation and transparency effects.
- 🎮 Intuitive keyboard controls for gameplay and difficulty selection.
- ☁️ Decorative graphics like clouds and custom shapes enhance visual appeal.

---

## 🛠️ Tools & Technologies

- **Language:** C
- **Graphics:** OpenGL & GLUT
- **Development Environment:**
  - macOS: Xcode
  - Windows: Code::Blocks

---

## 🎯 Gameplay Overview

- **Goal:** Destroy all bricks by bouncing a ball off a paddle without letting it fall.
- **Win Condition:** All bricks cleared.
- **Lose Condition:** Ball drops below the paddle.

---

## 🧩 Controls

| Key | Action |
|-----|--------|
| `e` | Select Easy Mode |
| `h` | Select Hard Mode |
| `a` | Move Paddle Left |
| `d` | Move Paddle Right |
| `Esc` | Exit the Game |

---

## 📐 Core Components

- `drawPaddle()` – Draws the paddle with blue color.
- `drawBall()` – Renders the ball with difficulty-dependent color.
- `drawBrick()` – Draws a single brick; color changes with difficulty.
- `drawBricks()` – Renders the full grid of bricks.
- `drawPopup()` – Displays game result or instructions.
- `drawEasyBackground()` & `drawHardBackground()` – Unique backgrounds based on difficulty.
- `update()` – Main game logic: collision detection, movement, score, win/loss checks.
- `keyboard()` – Keyboard input handling.
- `main()` – GLUT initialization and event loop setup.

---

## 🌈 Customization Ideas

- Add unique background themes and effects.
- Design personalized bricks and paddle shapes.
- Tweak animations and transitions.
- Implement multiplayer or advanced scoring mechanics.

---

## 🧠 My Role & Contributions

This project was built collaboratively, and I focused on:
- Core gameplay mechanics: paddle movement, ball dynamics, and collision logic.
- Implementing the real-time scoring and game state logic.
- Designing a difficulty selection system that changes visual styles and gameplay behavior.

---

## 📸 Screenshots

> *(Add screenshots or GIFs here to showcase your game!)*

---

## 🧪 How to Run

### On macOS (Xcode)

1. Clone the repository:
   ```bash
   git clone https://github.com/bla999ckt/PixelCraft/tree/main/C_and_OpenGl/breakout%20game
   ```
2. Open the `.xcodeproj` or `.c` in Xcode.
3. Build and run.

### On Windows (Code::Blocks)

1. Open the project or copy the source code into a new project.
2. Make sure GLUT and OpenGL libraries are installed.
3. Build and run.

---

## 💡 Future Improvements

- Add sound effects and background music.
- Create level progression and increasing difficulty.
- Introduce power-ups like multi-ball or extended paddle.
- Add saving high scores or pause/resume features.

---

## 🧾 License

MIT License 

---

## 🙌 Acknowledgements

Thanks to my teammates and mentors who contributed ideas, graphics, and feedback throughout development!
