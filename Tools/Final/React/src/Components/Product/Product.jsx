import React from 'react';

const Product = (props) => {
    const {id,title,image,price,description,rating}=props.pd
    return (
        <div>
            <div className="card bg-base-100 w-96 shadow-sm">
                <figure>
                    <img
                        src={image}/>
                </figure>
                <div className="card-body">
                    <h2 className="card-title">
                        {title}
                        <div className="badge badge-secondary">NEW</div>
                    </h2>
                    <p>{description.slice(0,150)}</p>
                    <div className="card-actions justify-end">
                        <div className="badge badge-outline">See More</div>
                        <div className="badge badge-outline">Add To Cart</div>
                    </div>
                </div>
            </div>

        </div>
    );
};

export default Product;