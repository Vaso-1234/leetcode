
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 0, y = 0;

        for (auto& p : positions) {
            x += p[0];
            y += p[1];
        }

        x /= positions.size();
        y /= positions.size();

        auto distSum = [&](double cx, double cy) {
            double sum = 0;

            for (auto& p : positions) {
                double dx = cx - p[0];
                double dy = cy - p[1];
                sum += sqrt(dx * dx + dy * dy);
            }

            return sum;
        };

        double step = 100.0;

        while (step > 1e-7) {
            bool improved = true;

            while (improved) {
                improved = false;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        double nx = x + dx * step;
                        double ny = y + dy * step;

                        if (distSum(nx, ny) < distSum(x, y)) {
                            x = nx;
                            y = ny;
                            improved = true;
                        }
                    }
                }
            }

            step *= 0.5;
        }

        return distSum(x, y);
    }
};