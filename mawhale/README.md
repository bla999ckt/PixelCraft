# Killer Whale Cursor Simulation - Pygame

## Description
This project is a **Killer Whale Cursor Simulation** built using **Pygame**. The whale follows the mouse cursor, leaving a smooth trail of segments behind it. The animation is achieved by using a sequence of images to create the illusion of fluid movement.

## Features
- Smooth movement of the whale following the cursor.
- Dynamic trail effect using multiple sprite segments.
- Custom images representing different parts of the whale.
- Adjustable speed and responsiveness.

## Installation
1. Clone the folder:
   ```sh
   svn export https://github.com/bla999ckt/PixelCraft/trunk/killer_whale_cursor
   cd killer_whale_cursor
   ```
2. Install dependencies:
   ```sh
   pip install pygame
   ```
3. Run the script:
   ```sh
   python whale.py
   ```

## Known Bug - Misalignment of Segments (15–21)
During development, we encountered a **persistent misalignment issue** affecting segments **15–21**. These segments contain additional visual elements above the whale's body, causing their centers to be miscalculated. Attempts to adjust their positions included:

1. **Applying a dynamic offset based on image height** → Helped but didn't fully resolve misplacement.
2. **Manually tweaking their starting positions** → Improved results but still slightly off.
3. **Adjusting the formula for segment spacing** → Helped, but some segments remain misaligned in specific movements.

### **Why the Bug Persists?**
- The images for segments **15–21** have varying heights, which causes inconsistent positioning.
- Adjusting offsets globally affects alignment for other segments.
- A more precise **image-based alignment system** may be needed, but was not fully implemented.

## Possible Fixes for the Future
- Implement **image metadata-based offsets** instead of fixed formulas.
- Use **precise bounding box calculations** instead of simple centering.
- Manually edit the images to ensure they have consistent visual alignment.

## Contributions
If you'd like to help fix this issue, feel free to **submit a pull request** or suggest alternative solutions!

