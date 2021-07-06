n = input("Ordine matrici: ");
%Saranno usate: 
%Matrice di Vandermonde
%Matrice di Hilbert
%Matrice tridiagonale




r1 = rand(n, 1);
V = vander(r1)
H = hilb(n)

r2 = rand((n-1), 1);
D = diag(r1) + diag(r2, +1) + diag(r2, -1)

norms = zeros(4,3);
M = {V, H, D};

for k = 1:3
        norms(1,k) = norm1(M{k}, n);
        norms(2,k) = norm2(M{k}, n);
        norms(3,k) = normFro(M{k}, n);
        norms(4,k) = normInf(M{k}, n);
end
disp 'Vandermonde, Hilbert, Tridiagonal'
norms

function result = norm1(matrix, n)
    result = 0;
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

function result = norm2(matrix, n)
    result = max(abs(eig(matrix' * matrix)));
end

function result = normFro(matrix, n)
    result = 0;
    for j = 1:n
        for i = 1:n
            result = result + matrix(i, j)*matrix(i,j);
        end
    end
    result = sqrt(result);
end

function result = normInf(matrix, n)
    result = 0;
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
