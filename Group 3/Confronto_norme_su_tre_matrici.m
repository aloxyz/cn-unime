%Calcola le 4 norme matriciali studiate delle 3 matrici di ordine n
n = input("Ordine matrici: ");
%Saranno usate: 
%Matrice di Vandermonde
%Matrice di Hilbert
%Matrice tridiagonale

r1 = rand(n, 1)*5;
V = vander(r1);
H = hilb(n);

r2 = rand((n-1), 1)*10;
D = diag(r1) + diag(r2, +1) + diag(r2, -1);

norms = zeros(4,3);
M = {V, H, D};

for k = 1:3
        norms(1,k) = norm1(M{k});
        norms(2,k) = norm2(M{k});
        norms(3,k) = normFro(M{k});
        norms(4,k) = normInf(M{k});
end

uitable(figure(1), 'Data', norms, 'ColumnName',{'Vandermonde', 'Hilbert', 'Tridiagonale'}, 'RowName', {'1', '2', 'Fro', 'Inf'});

function result = norm1(matrix) %Calcola la massima sommatoria di ogni colonna
    result = 0;
    n = size(matrix, 1);
    for j = 1:n
        tmp = 0;
        for i = 1:n
            tmp = tmp + abs(matrix(i,j));
        end
        if tmp > result
            result = tmp;
        end
    end
end

function result = norm2(matrix) %Trova la radice quadrata del massimo autovalore della matrice
    result = sqrt(max(abs(eig(matrix' * matrix))));
end

function result = normFro(matrix) %Calcola la somma dei quadrati di ogni elemento
    result = 0;
    n = size(matrix, 1);
    for j = 1:n
        for i = 1:n
            result = result + matrix(i, j)*matrix(i,j);
        end
    end
    result = sqrt(result);
end

function result = normInf(matrix) %Calcola la massima sommatoria di ogni riga
    result = 0;
    n = size(matrix, 1);    
    for i = 1:n
        tmp = 0;
        for j = 1:n
            tmp = tmp + abs(matrix(i,j));
        end
        if tmp > result
            result = tmp;
        end
    end
end
