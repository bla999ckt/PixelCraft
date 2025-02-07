Whale Simulation - Pygame

Description

This project is a whale trail simulation built using Pygame. The whale follows the mouse cursor, leaving a smooth trail of segments behind it. The animation is achieved by using a sequence of images to create the illusion of fluid movement.

Features

Smooth movement of the whale following the cursor.

Dynamic trail effect using multiple sprite segments.

Custom images representing different parts of the whale.

Adjustable speed and responsiveness.

Installation

Clone the repository:

git clone https://github.com/yourusername/whale-trail.git
cd whale-trail

Install dependencies:

pip install pygame

Run the script:

python whale.py

Known Bug - Misalignment of Segments (15–21)

During development, we encountered a persistent misalignment issue affecting segments 15–21. These segments contain additional visual elements above the whale's body, causing their centers to be miscalculated. Attempts to adjust their positions included:

Applying a dynamic offset based on image height → Helped but didn't fully resolve misplacement.

Manually tweaking their starting positions → Improved results but still slightly off.

Adjusting the formula for segment spacing → Helped, but some segments remain misaligned in specific movements.

Why the Bug Persists?

The images for segments 15–21 have varying heights, which causes inconsistent positioning.

Adjusting offsets globally affects alignment for other segments.

A more precise image-based alignment system may be needed, but was not fully implemented.

Possible Fixes for the Future

Implement image metadata-based offsets instead of fixed formulas.

Use precise bounding box calculations instead of simple centering.

Manually edit the images to ensure they have consistent visual alignment.

Contributions

If you'd like to help fix this issue, feel free to submit a pull request or suggest alternative solutions!

License

MIT License.
