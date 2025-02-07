import pygame
import math

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((960, 720))
clock = pygame.time.Clock()

class TrailSegment(pygame.sprite.Sprite):
    def __init__(self, index, costumes):
        super().__init__()
        self.index = index
        self.costumes = costumes
        self.image = pygame.image.load(costumes[index]['path']).convert_alpha()
        self.rect = self.image.get_rect()

        self.pos = pygame.math.Vector2(0, 0)
        self.target_pos = pygame.math.Vector2(0, 0)

        self.rect.center = (round(self.pos.x), round(self.pos.y))

        
    def update(self, mouse_positions):
        if self.index >= len(mouse_positions):
            return
            
        self.target_pos = pygame.math.Vector2(
            mouse_positions[self.index][0],
            mouse_positions[self.index][1] + 30
        )
        
        # Calculate movement
        dx = self.target_pos.x - self.pos.x
        dy = self.target_pos.y - self.pos.y
        distance = math.hypot(dx, dy)
        
        if distance > 1:
            if distance > 15:
                move_distance = 7
            else:
                move_distance = 0.3 * distance
            
            if dx or dy:
                direction = math.degrees(math.atan2(dy, dx))  # atan2(dy, dx) is correct order
                self.pos += pygame.math.Vector2.from_polar((move_distance, direction))

        else:
            self.pos = self.target_pos.copy()
        
        self.rect.center = (round(self.pos.x), round(self.pos.y))
        

class Game:
    def __init__(self):
        self.running = True
        self.mouse_positions = []
        self.trail_segments = []
        self.costumes = self.load_costumes()
                
        for i in range(44):
            segment = TrailSegment(i, self.costumes)
            self.trail_segments.append(segment)

        
    def load_costumes(self):
        costumes = []
        costume_files = [
        "assets/aa8294313b28030f9de68d500ff0fdb9.png",
        "assets/031fb594a342b52083bc39e33f631c6f.png",
        "assets/7b3fd4685e707307f1feb6a159319802.png",
        "assets/aa650828a4e5a1a228495885fed8fd8e.png",
        "assets/75dbf16a3043fe8fe2ebdfe6335c8a08.png",
        "assets/70de459c0d7e2ab013740af847948710.png",
        "assets/d4b114f4ffc9974e2707947f0416f025.png",
        "assets/dd749a0c73ac6b5b567b2b46e5d5917e.png",
        "assets/5366553be1f037d71a336fb11e6cdac4.png",
        "assets/736c27e19f4a230a833e7036e8c71cac.png",
        "assets/b5cb662ac8fa9e88d1e9206c05da09c8.png",
        "assets/8ea12cea4b03d2fb5ca357e6946550bb.png",
        "assets/131f446a2046d07bebd2b96cf03f9472.png",
        "assets/41c8d8236b0e7ae22e01827da316ac1f.png",
        "assets/73be23ce0d2bf861ea4119d096579e8d.png",
        "assets/d8d74a361323b96a42d824ece1fb3e66.png",
        "assets/227b0b8bb849cbd45e9afb571432c3d5.png",
        "assets/d9380c0c0aa5e38e9ad617d537d6a37b.png",
        "assets/1d72b6253e7f09ab6c2c816e0e55c97b.png",
        "assets/5a58e72481952ad64179ba34f7341eb0.png",
        "assets/1991ba588bad2450dbd79cd09fdaf145.png",
        "assets/c59551a5d0c8c7b81a683f4e39937988.png",
        "assets/6f109408967163f9cfe1f0a0921e162c.png",
        "assets/4b76d8190bc0d7e4abca7c045e2873ff.png",
        "assets/7da9912af7c4d384c3fa93863c5cb8b5.png",
        "assets/871f19bcce4af744fc1d85bf0fc0f723.png",
        "assets/c9e9d0b7c869cc17ffa45cca4f672100.png",
        "assets/e5bb4c217967ec67bf579d9f8f14d91c.png",
        "assets/9061d549c50838f005189cf3a92c34a5.png",
        "assets/cdedcecd2471e8deff0004e0af448e1e.png",
        "assets/0054a1ddbe7253fd0c6be24c531cf02b.png",
        "assets/786383df76fc13feb9c87251b3ac4bb4.png",
        "assets/0df2969ffcfd0e8770290d9a512fb227.png",
        "assets/6d8c1a91e6be9e7c782150543f8154ec.png",
        "assets/728951daab585b63b007b2aad3f31465.png",
        "assets/2283ccb2a9ca819cd9490adaf7f3441f.png",
        "assets/cb322de97de130652442ccf3d85e931b.png",
        "assets/8e45c12e42a08f8f4bea6385afce9354.png",
        "assets/eb979177ed6d0c9aa6d395f2b4ffeaaa.png",
        "assets/2333568f49a1c6ce95e57eb3567b5cd0.png",
        "assets/997169d5144453eefc7f3951bb13d87a.png",
        "assets/03d9aa3a5514ae3c1cde12f51c396a62.png",
        "assets/b9e800972318031876e26a2e0afd74c9.png",
        "assets/91d0b2660da9e1cc35b24f077e1f7f08.png",
        "assets/031fb594a342b52083bc39e33f631c6f.png"
        ]
        
        for idx, path in enumerate(costume_files):
            costumes.append({
                'path': path,
                'center': (36 + idx*5, -56) 
            })
        return costumes
    
    def run(self):
        while self.running:
            # Handle events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.running = False
            
            # Update mouse positions
            mouse_pos = pygame.mouse.get_pos()
            self.mouse_positions.insert(0, mouse_pos)
            if len(self.mouse_positions) > 44:
                self.mouse_positions.pop()
            
            # Update trail segments
            for i, segment in enumerate(self.trail_segments):
                if i < len(self.mouse_positions):
                    segment.update(self.mouse_positions)
            
            # Draw everything
            screen.fill((255, 255, 255))
            
            # Draw segments in reverse order (oldest first)
            for segment in reversed(self.trail_segments):
                if segment.index < len(self.mouse_positions):
                    screen.blit(segment.image, segment.rect)
            
            pygame.display.flip()
            clock.tick(60)

if __name__ == "__main__":
    game = Game()
    game.run()
    pygame.quit()
        