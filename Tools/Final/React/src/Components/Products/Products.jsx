import React, { useEffect, useState } from 'react';
import { useLoaderData } from 'react-router';
import Product from '../Product/Product';

const Products = () => {

     const  records  = useLoaderData();

     console.log(records)



    


    return (
        <div className='grid grid-cols-3 gap-5 mt-10 p-10'>
            {
                records.map(product=>           <Product  pd={product}></Product>     )
            }
        </div>
    );
};

export default Products;