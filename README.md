Raycaster_Maze

Raycaster Maze
Tagline: Explore the Depths of Raycasting in a 3D Maze World.

2. Team Members
Name
Role
Role Reason
Dumebi Anyamkpa
<anyamkpa.ifeanyi@gmail.com>
Front-end wall creation
Graphics Designer & Texture Artist
Responsible for designing graphics, creating textures, and ensuring visual appeal throughout the game.
Interests in game design and map building.

These roles have been decided based on each member's skills and interests, ensuring a balanced team capable of covering both technical and creative aspects of the project.


3. Technologies
Languages: C
Library: SDL2
Other Options Considered:
Alternative library: OpenGL
Trade-offs: SDL2 provides a higher level of abstraction, making it easier to work with for beginners. However, OpenGL offers more flexibility and control over rendering.
Final Decision: SDL2 was chosen due to its simplicity and suitability for the scope of the project.
Alternative language: Python
Trade-offs: Python provides object-oriented features that could simplify certain aspects of the project. However, C is more straightforward for low-level programming, which aligns better with the project's requirements.
Final Decision: C was chosen to maintain simplicity and compatibility with the provided curriculum and requirements.

4. Challenge statement
Problem: Raycaster Adventures aims to provide a hands-on learning experience in game development through the implementation of a 3D raycasting-based game.
What It Will Not Solve: This project will not aim to create a fully polished commercial game but rather focus on educational aspects and core gameplay mechanics.
Audience: The project will help aspiring game developers, students, and enthusiasts interested in understanding the fundamentals of ray casting and 3D game development.
Locale Dependency: The project is not dependent on any specific locale and can be accessed globally.

5. Risks
Technical Risks: Potential challenges may arise in implementing advanced features such as collision detection or texture mapping. Safeguards include thorough testing and iterative development.
Non-Technical Risks: Risks such as scope creep or team dynamics could impact project progress. Strategies include clear communication, regular team meetings, and setting realistic goals.

6. Infrastructure
Branching and Merging: The team (if i had one) will follow the GitHub flow, utilizing feature branches for development and merging changes into the main branch after code review.
Deployment Strategy: Deployment will involve compiling the code on Ubuntu 20.04 LTS using gcc and ensuring compatibility with the specified environment.
Data Population: Initial data for the game, such as map layouts, may be hardcoded or loaded from external files.
Testing: Testing will be conducted manually during development, with plans to implement automated testing using the framework SDL2_Test.

7. Existing Solutions
Similar products include classic raycasting games like Wolfenstein 3D or contemporary indie titles like DUSK. Raycaster Adventures aims to offer a similar gameplay experience while focusing on educational aspects and providing a customizable environment for learning.


ARCHITECTURE
Here's a simplified architecture diagram illustrating the MVP for the Raycaster Maze project. Since the project involves developing a 3D raycasting game using C and SDL2, the architecture will primarily focus on the game engine components and their interactions. Below is my representation of the architecture, detailing the flow of data through the system:

1. User Input:
   - Player input from keyboard. (wasd)
   - Interacts with the game loop to update player movement and camera orientation.

2. Game Loop:
   - Controls the flow of the game.
   - Updates game state, including player position, camera orientation, and rendering.

3. Rendering Engine:
   - Converts game state into visual output.
   - Utilizes raycasting technique to render 3D environment.
   - Draws walls, textures, and other graphical elements onto the screen.

4. Collision Detection:
   - Checks for collisions between the player and walls or other objects in the game world.
   - Determines player movement and interaction based on collision detection results.

5. Map Parser:
   - Reads map data from external files.
   - Converts map data into a format usable by the game engine.

6. Texture Loader:
   - Loads textures for walls, floors, ceilings, etc., from external image files.
   - Converts image data into a format usable by the rendering engine.

7. Game State Management:
   - Stores and manages the current state of the game.
   - Includes player position, camera orientation, map layout, and other relevant data.

8. Audio Engine (Optional):
   - Manages sound effects and background music.
   - Integrates with the rendering engine to synchronize audio with visual events.

9. UI Components (Optional):
   - Displays user interface elements such as menus, HUDs, or in-game messages.
   - Interacts with the game loop to update UI elements based on game events.

10. Error Handling and Logging:
    - Manages error handling and logging throughout the application.
    - Provides feedback to developers and users in case of errors or unexpected behavior.

This textual representation provides an overview of the key components and their interactions within the raycaster.


DATA MODEL
In this diagram:

Player: Represents the player entity in the game. It includes attributes such as id, position (x, y), angle, health, etc.
Map: Represents the game map entity. It includes attributes such as id, width, height, and the map data itself stored as text.
Texture: Represents textures used for walls, floors, ceilings, etc. It includes attributes such as id, name, and the image data stored as a blob.
This simple text-based diagram illustrates the basic data model for storing player data, map data, and textures in the Raycaster Maze project.


-- **************************** SqlDBM: MySQL ***************************
-- ************************************** `Player`
CREATE TABLE `Player`
(
 `id`            varchar(125) NOT NULL ,
 `position_x`    float NOT NULL ,
 `position_y`    float NOT NULL ,
 `orientation`   float NOT NULL ,
 `speed`         float NOT NULL ,
 `health`        int NOT NULL ,
 `inventory`     varchar(255) NOT NULL ,
 `status`        varchar(45) NOT NULL ,

PRIMARY KEY (`id`)
);

-- ************************************** `Map`
CREATE TABLE `Map`
(
 `id`             varchar(125) NOT NULL ,
 `layout`         text NOT NULL ,
 `texture_id`     varchar(125) NOT NULL ,

PRIMARY KEY (`id`)
);

-- ************************************** `Texture`
CREATE TABLE `Texture`
(
 `id`             varchar(125) NOT NULL ,
 `type`           varchar(45) NOT NULL ,
 `image_url`      varchar(255) NOT NULL ,

PRIMARY KEY (`id`)
);

-- ************************************** `GameState`
CREATE TABLE `GameState`
(
 `id`             varchar(125) NOT NULL ,
 `player_id`      varchar(125) NOT NULL ,
 `map_id`         varchar(125) NOT NULL ,

PRIMARY KEY (`id`),
KEY `FK_Player` (`player_id`),
CONSTRAINT `FK_Player` FOREIGN KEY (`player_id`) REFERENCES `Player` (`id`),
KEY `FK_Map` (`map_id`),
CONSTRAINT `FK_Map` FOREIGN KEY (`map_id`) REFERENCES `Map` (`id`)
);

-- ************************************** `SoundEffect`
CREATE TABLE `SoundEffect`
(
`id`             varchar(125) NOT NULL ,
`name`           varchar(45) NOT NULL ,
 `file_url`       varchar(255) NOT NULL ,

PRIMARY KEY (`id`),
);

-- ************************************** `GameEvent`
CREATE TABLE `GameEvent`
(
 `id`             varchar(125) NOT NULL ,
 `type`           varchar(45) NOT NULL ,
 `description`    varchar(255) NOT NULL ,
 `trigger_time`   datetime NOT NULL ,
 `player_id`      varchar(125) NOT NULL ,

PRIMARY KEY (`id`),
KEY `FK_Player` (`player_id`),
CONSTRAINT `FK_Player` FOREIGN KEY (`player_id`) REFERENCES `Player` (`id`)
);

User Stories
1. As a Player, I want to navigate through the 3D environment using keyboard inputs, so I can explore the game world and engage with different elements.
   - Acceptance Criteria:
     - The player can move forward, backward, strafe left, and strafe right using W, S, A, and D keys.
     - The player can rotate the camera left and right using the left and right arrow keys.

2. As a Player, I want to see realistic wall textures in the game, so I can have a visually immersive experience.
   - Acceptance Criteria:
     - Walls in the game should have different textures based on their type (e.g., brick, wood, concrete).
     - Textures should be applied correctly, providing a realistic and visually appealing environment.

3. As a Player, I want to experience collisions with walls, preventing me from moving through them, so the game adheres to realistic movement constraints.
   - Acceptance Criteria:
     - The player should not be able to move through walls; collisions should stop or slide the player along the wall's surface.
     - The player's movement should be restricted based on the map layout.

4. As a Player, I want to load different maps from external files, allowing for varied gaming experiences, so I can explore diverse environments.
   - Acceptance Criteria:
     - The game should provide a file input option to load different map layouts during runtime.
     - Maps loaded from external files should be rendered correctly, reflecting the specified layout and textures.

5. As a Player, I want to be able to toggle the map display on and off during gameplay, so I can navigate through the environment with or without the map overlay.
   - Acceptance Criteria:
     - The player can press a designated key to toggle the map display on and off.
     - The map overlay should accurately represent the player's line of sight and surroundings.

Potential Pitfalls:

1. Overly General User Stories:
   - Pitfall: Writing stories like "As a user, I want a good game," can lead to unclear requirements and undefined acceptance criteria.
   - Mitigation: Ensure each user story is specific, measurable, and includes well-defined acceptance criteria.

2. Assuming Implementation:
   - Pitfall: Describing the solution in the user story rather than the desired functionality.
   - Mitigation: Focus on the user's perspective and desired outcomes rather than dictating how the solution should be implemented.

3. Neglecting Edge Cases:
   - Pitfall: Overlooking specific scenarios or edge cases that might impact user satisfaction.
   - Mitigation: Consider various scenarios and include acceptance criteria for edge cases in user stories.

4. Lack of Priority:
   - Pitfall: Failing to prioritize user stories, leading to unclear development focus.
   - Mitigation: Prioritize user stories based on their importance and impact, ensuring a clear development roadmap.


Mockup


