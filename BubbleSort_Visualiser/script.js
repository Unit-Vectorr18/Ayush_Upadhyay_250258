const arrayInput=document.getElementById("arrayInput");
const randomBtn=document.getElementById("randomBtn");
const visualizeBtn=document.getElementById("visualizeBtn");
const sortBtn=document.getElementById("sortBtn");
const pauseBtn=document.getElementById("pauseBtn");
const resumeBtn=document.getElementById("resumeBtn");
const resetBtn=document.getElementById("resetBtn");
const sizeSlider=document.getElementById("sizeSlider");
const speedSlider=document.getElementById("speedSlider");
const sizeValue=document.getElementById("sizeValue");
const speedValue=document.getElementById("speedValue");
const visualizationArea=document.getElementById("visualizationArea");
const beforeArray=document.getElementById("beforeArray");
const afterArray=document.getElementById("afterArray");
const swapCount=document.getElementById("swapCount");

let array=[],originalArray=[],swaps=0;
let paused=false,sorting=false,cancel=false;

const delay=()=>400/Number(speedSlider.value);
const sleep=(ms)=>new Promise(r=>setTimeout(r,ms));
async function hold(){while(paused&&!cancel) await sleep(60);}

sizeSlider.oninput=()=>sizeValue.textContent=sizeSlider.value;
speedSlider.oninput=()=>speedValue.textContent=speedSlider.value+"x";

function generateRandomArray(){
 array=[];
 for(let i=0;i<+sizeSlider.value;i++) array.push(Math.floor(Math.random()*496)+5);
 arrayInput.value=array.join(",");
}

function parseArray(){
 const vals=arrayInput.value.split(",").map(v=>v.trim()).filter(v=>v!=="");
 if(!vals.length){alert("Enter an array");return false;}
 if(vals.length>100){alert("Maximum size is 100");return false;}
 array=[];
 for(const v of vals){
   const n=Number(v);
   if(Number.isNaN(n)){alert("Invalid input");return false;}
   array.push(n);
 }
 sizeSlider.value=array.length;
 sizeValue.textContent=array.length;
 return true;
}

function drawBars(){
 visualizationArea.innerHTML="";
 const mn=Math.min(...array),mx=Math.max(...array),rg=Math.max(1,mx-mn);
 array.forEach(v=>{
   const b=document.createElement("div");
   b.className="bar blue";
   b.style.height=((v-mn)/rg*300+20)+"px";
   visualizationArea.appendChild(b);
 });
}
function updateBars(){
 const bs=document.querySelectorAll(".bar");
 const mn=Math.min(...array),mx=Math.max(...array),rg=Math.max(1,mx-mn);
 array.forEach((v,i)=>bs[i].style.height=((v-mn)/rg*300+20)+"px");
}
function visualize(){
 if(!parseArray()) return;
 originalArray=[...array];
 beforeArray.textContent="["+originalArray.join(", ")+"]";
 afterArray.textContent="--";
 swaps=0;
 swapCount.textContent="0";
 drawBars();
}
const bars=()=>document.querySelectorAll(".bar");
const setColor=(i,c)=>bars()[i].className="bar "+c;

async function bubbleSort(){
 if(sorting) return;
 if(!bars().length) visualize();
 sorting=true; cancel=false; paused=false;

 for(let i=0;i<array.length-1 && !cancel;i++){
   for(let j=0;j<array.length-1-i && !cancel;j++){
     await hold();
     setColor(j,"yellow");
     setColor(j+1,"yellow");
     await sleep(delay());

     if(array[j]>array[j+1]){
       setColor(j,"red");
       setColor(j+1,"red");
       await sleep(delay()/2);
       [array[j],array[j+1]]=[array[j+1],array[j]];
       swaps++;
       swapCount.textContent=swaps;
       updateBars();
       await sleep(delay()/2);
     }

     if(!bars()[j].classList.contains("green"))
        setColor(j,"blue");
     if(!bars()[j+1].classList.contains("green"))
        setColor(j+1,"blue");
   }

   // Highlight sorted portion 
   setColor(array.length-1-i,"green");
 }

 if(!cancel){
   setColor(0,"green");
   afterArray.textContent="["+array.join(", ")+"]";
 }
 sorting=false;
}

function resetAll(){
 cancel=true;
 paused=false;
 sorting=false;
 array=[...originalArray];
 swaps=0;
 swapCount.textContent="0";
 afterArray.textContent="--";
 if(array.length) drawBars();
}

randomBtn.onclick=generateRandomArray;
visualizeBtn.onclick=visualize;
sortBtn.onclick=bubbleSort;
pauseBtn.onclick=()=>paused=true;
resumeBtn.onclick=()=>paused=false;
resetBtn.onclick=resetAll;

generateRandomArray();
visualize();
