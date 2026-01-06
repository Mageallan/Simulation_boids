#pragma once
#include <stdexcept> // Pour les exceptions
namespace bd {

	template<typename T>
	class DynamicArray {
	private:
		T* data;               // Pointeur vers le tableau dynamique
		int high;              // Nombre d'éléments actuellement stockés
		int currentCapacity;   // Capacité actuelle du tableau

		void resize(int newCapacity) {
			T* newData = new T[newCapacity];
			for (int i = 0; i < high; ++i) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			currentCapacity = newCapacity;
		}

	public:
		// Constructeur par défaut
		DynamicArray(int initialCapacity = 10)
			: high(0), currentCapacity(initialCapacity) {
			data = new T[currentCapacity];
		}

		// Destructeur
		~DynamicArray() {
			delete[] data;
		}

		// Ajouter un élément à la fin
		void push_back(const T& value) {
			if (high == currentCapacity) {
				resize(currentCapacity * 2); // Double la capacité si pleine
			}
			data[high++] = value;
		}

		// Accéder à un élément par index
		T& operator[](int index) {
			if (index < 0 || index >= high) {
				throw std::out_of_range("Index out of range");
			}
			return data[index];
		}


		const T& operator[](int index) const {
			if (index < 0 || index >= high) {
				throw std::out_of_range("Index out of range");
			}
			return data[index];
		}

		// Obtenir la taille actuelle
		int size() const {
			return high;
		}

		// Obtenir la capacité actuelle
		int capacity() const {
			return currentCapacity;
		}
	};

}