// 100 % O(N) solution
struct Wall {
    int current_height = 0;
    vector<int> brick_heights;
    int total_bricks = 0;

    void add_brick(int h) {
        // Do nothing if the bricks dont need to be modified
        if (h == current_height) return;
        // Add new brick
        if (h > current_height) {
            brick_heights.push_back(h - current_height);
            ++total_bricks;
            current_height = h;
        }
        // Remove bricks until one can add some
        while (h < current_height) {
            current_height -= brick_heights.back();
            brick_heights.pop_back();
        }
        add_brick(h);
    }
};

int solution(vector<int> &H) {
    Wall wall;

    for (auto &h : H) wall.add_brick(h);

    return wall.total_bricks;
}
