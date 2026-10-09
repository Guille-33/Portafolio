clear
clc
C1=0;%Nº current sources individual for a mesh
C2=0;%Nº current sources between two meshes
NR=0;%Nº individual resistances for a mesh
NR2=0;%Nº shared resistances
NV=0;%Nº shared batteries
%most of the whiles found on the codes are used to make sure that the user enters the correct values and letters
fprintf("Hello, this program is used to solve DC circuits by mesh method\n\n");
M=input('Please, assign a number to each mesh and enter the total number of meshes in the circuit: ');
%The matrix Matshare will save in each row the corresponding to the meshes and in each column the number of shared meshes.
Matshare=connection(M);
%The matrix E (1xM) stores in each column (corresponding to the meshes) the number of elements of the mesh
E=zeros(1,M);
for mesh=1:M
  fprintf('\nEnter the total number of elements for mesh %d\n(if shared elements consider them for each mesh): ',mesh);
  E(1,mesh)=input('');
end
%N is the formula for the maximum number of connections
N=(M*(M-1))/2;
%Matrix (Mx6) used for the resolution of the exercise, the first 3 columns correspond to I1 I2 and I3, and then the last 3 are marked with a 1 if there is a current source, in order to calculate its voltage
Matmesh=zeros(M,M+N);
%Matrix (Mx1) used for the resolution of the exercise, with all the voltages (doesn’t depend on current so it must be taken out of Matmesh)
Matindep=zeros(M,1);
%cell array used to store all the values of the elements as in Matmesh they are added, the first matrix is for the resistors, the 2nd for voltages and the 3rd for currents. In all three the rows correspond to every mesh
elements={zeros(M,max(E)),zeros(M,max(E)),zeros(M,max(E))};
%loop used to ask for each of the elements in the meshes
for mesh=1:M
  %M number of meshes
  fprintf('\n\nEnter each element for mesh %d:',mesh);
  for i=1:E(mesh)
      %i number of the elements
      fprintf('\n   Element %d:\n\n',i);
%function list is created to store the values and what type of element is. Then passed to the main code in T(for the type) and V(for the value taking into account also the sign)
       [T,V]=list();
       if ~isempty(find(Matshare(mesh,:)~=0,1))
           fprintf("\nIs this element between 2 meshes?(Y)=YES (N)=NO: ");
           resp=answer();

           if strcmp('N',resp)==1 || strcmp('n',resp)==1
               fprintf("\nElement belonging only to mesh %i\n",mesh);
               switch T

  %storing the values in each of the matrices according to the type of element
                  case 'R'
                      Matmesh(mesh,mesh)=Matmesh(mesh,mesh)+abs(V);
                      elements{1,1}(mesh,i)=V;
                      NR=NR+1;
                  case 'r'
                      Matmesh(mesh,mesh)=Matmesh(mesh,mesh)+abs(V);
                      elements{1,1}(mesh,i)=V;
                      NR=NR+1;
                  case 'V'
                      Matindep(mesh,1)=Matindep(mesh,1)-V;
                      elements{1,2}(mesh,i)=V;
                  case 'v'
                      Matindep(mesh,1)=Matindep(mesh,1)-V;
                      elements{1,2}(mesh,i)=V;
                  case 'C'
                      [Matmesh,Matindep]=extra(M,Matmesh,Matindep,mesh,0,V,N);
                      elements{1,3}(mesh,i)=V;
                      C1=C1+1;
                  case 'c'
                      [Matmesh,Matindep]=extra(M,Matmesh,Matindep,mesh,0,V,N);
                      elements{1,3}(mesh,i)=V;
                      C1=C1+1;
              end
          end
          if strcmp('Y',resp)==1 || strcmp('y',resp)==1
              switch T
  %storing the values in each of the matrices according to the type of element
                  case 'R'
                      Matmesh(mesh,mesh)=Matmesh(mesh,mesh)+abs(V);
                      elements{1,1}(mesh,i)=V;
                      NR2=NR2+1;
                  case 'r'
                      Matmesh(mesh,mesh)=Matmesh(mesh,mesh)+abs(V);
                      elements{1,1}(mesh,i)=V;
                      NR2=NR2+1;
                  case 'V'
                      elements{1,2}(mesh,i)=V;
                      NV=NV+1;
                  case 'v'
                      elements{1,2}(mesh,i)=V;
                      NV=NV+1;
              end
              fprintf("What other mesh does it belong to?");
              fprintf(' %d?',Matshare(mesh,:));
              resp=input("\nENTER THE MESH NUMBER IT ALSO BELONGS TO: ");
             
              while resp~=Matshare(mesh,:)
                  fprintf('\nIf it isn´t connected to any other mesh, please enter 0\nIf it is, please enter one of these numbers: ');
                  fprintf(' %d',Matshare(mesh,:)); %fprintf for writing possible connections of that mesh
                  resp=input("\nENTER :");
                  if resp==0
                      break
                  end
              end
              if resp~=0
                  switch T
                      case 'R'
                          Matmesh(mesh,resp)=Matmesh(mesh,resp)-abs(V);
                      case 'r'
                          Matmesh(mesh,resp)=Matmesh(mesh,resp)-abs(V);
                      case 'V'
                          Matindep(resp,1)=Matindep(resp,1)+V;
                      case 'v'
                          Matindep(resp,1)=Matindep(resp,1)+V;
                      case 'C'
                          elements{1,3}(mesh,i)=V;
                          [Matmesh,Matindep]=extra(M,Matmesh,Matindep,mesh,resp,V,N);
                         C2=C2+1;
                      case 'c'
                          elements{1,3}(mesh,i)=V;
                          [Matmesh,Matindep]=extra(M,Matmesh,Matindep,mesh,resp,V,N);
                          C2=C2+1;
                  end
              end
          end
      end
  end
end
Matvar=linsolve(Matmesh,Matindep);
for mesh=1:M
  fprintf("The current of mesh %i is:%f Amps\n",mesh,Matvar(mesh,1));
end
for i=(N+M+1):(N+M+C1+C2)
  fprintf("The voltage drop of a current source in mesh %i is:%f volts",i-M-N,Matvar(i,1));
end
%If wanted the program can also get the power consumed and generated by each element
fprintf("\nDo you want to check the power balance?(Y/N):  ");
resp=answer();
NR=NR+(NR2/2);%over two to avoid counting two times
NV=NV/2;%over two to avoid counting two times
if strcmp('Y',resp)==1 || strcmp('y',resp)==1
  powerbalance(elements,Matvar,E,M,N,Matmesh,NR,NV);
elseif strcmp('N',resp)==1 || strcmp('n',resp)==1

  fprintf("\n Are you sure? CONFIRM (Y/N): ");
  resp=answer();
  if strcmp('Y',resp)==1 || strcmp('y',resp)==1
fprintf("Thank you for using our program.\nGoodbye");

      elseif strcmp('N',resp)==1 || strcmp('n',resp)==1
  
fprintf("\n Calculating the power balance...: ");
powerbalance(elements,Matvar,E,M,N,Matmesh,NR,NV);

      
  end

end

