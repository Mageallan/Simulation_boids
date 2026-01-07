#include "Flock.h"

namespace bd {

    /**
     * @brief Construit un groupe (flock) contenant un certain nombre de boids.
     *
     * Chaque boid est initialisé avec une position et une vitesse aléatoires.
     *
     * @param count Nombre de boids à créer.
     */
    Flock::Flock(int count) { 
        for (int i = 0; i < count; ++i) { 
            Boid b; 
            b.position = Vec2<float>(rand() % 800, rand() % 600);
            b.velocity = Vec2<float>(
                (rand() % 200 - 100) / 100.f,
                (rand() % 200 - 100) / 100.f
            );
            boids.push_back(b);
        }
    }

    /**
     * @brief Ajoute un boid au groupe.
     *
     * @param b Boid à ajouter.
     */
    void Flock::addBoid(const Boid& b) {
        boids.push_back(b);
    }

    /**
     * @brief Ajoute un boid généré aléatoirement.
     *
     */
    void Flock::addRandomBoid() {
        if (boids.size() >= 200) return;

        Boid b;

        // Position aléatoire
        b.position = Vec2<float>(
            rand() % 800,
            rand() % 600
        );

        // Vitesse aléatoire
        b.velocity = Vec2<float>(
            (rand() % 200 - 100) / 100.f,
            (rand() % 200 - 100) / 100.f
        );

        boids.push_back(b);
    }

    /**
     * @brief Supprime le dernier boid du groupe.
     *
     */
    void Flock::removeLastBoid() {
        if (boids.size() > 10) {
            boids.pop_back();
        }
    }

    /**
     * @brief Renvoie le nombre de boids dans le groupe.
     *
     * @return Nombre de boids.
     */
    int Flock::size() const {
        return boids.size();
    }

    /**
     * @brief Accès à un boid par index.
     *
     * @param index Position du boid dans le tableau.
     * @return Référence vers le boid.
     */
    Boid& Flock::operator[](int index) {
        return boids[index];
    }

    /**
     * @brief Accès constant à un boid par index.
     *
     * @param index Position du boid dans le tableau.
     * @return Référence constante vers le boid.
     */
    const Boid& Flock::operator[](int index) const {
        return boids[index];
    }

    /**
     * @brief Renvoie une référence constante vers le tableau interne de boids.
     *
     * @return Référence constante vers DynamicArray<Boid>.
     */
    const DynamicArray<Boid>& Flock::getBoids() const {
        return boids;
    }

    /**
     * @brief Trouve les voisins d'un boid dans un rayon donné.
     *
     * Parcourt tous les boids du groupe et renvoie ceux dont la distance
     * au boid cible est inférieure ou égale au rayon spécifié.
     *
     * @param index Index du boid dont on cherche les voisins.
     * @param radius Rayon de perception.
     * @return DynamicArray<Boid> contenant les voisins trouvés.
     */
    DynamicArray<Boid> Flock::findNeighbors(int index, float radius) const {

        DynamicArray<Boid> neighbors;

        if (index >= boids.size())
            return neighbors; // sécurité

        const Boid& b = boids[index];
        float radiusSq = radius * radius;

        for (int i = 0; i < boids.size(); ++i) {
            if (i == index) continue; // ne pas se comparer à soi-même

            const Boid& other = boids[i];

            // distance au carré 
            Vec2<float> diff = other.position - b.position;
            float distSq = diff.x * diff.x + diff.y * diff.y;

            if (distSq <= radiusSq)
                neighbors.push_back(other);
        }

        return neighbors;
    }

} // namespace bd
